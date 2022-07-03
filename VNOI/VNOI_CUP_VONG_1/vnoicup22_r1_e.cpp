#include <bits/stdc++.h>

using i64 = long long;

template <class Fun>
struct y_combinator {
	Fun fun_;
	template <class... Args>
	decltype(auto) operator()(Args&&... args) const {
		return fun_((*this), std::forward<Args>(args)...);
	}
};

template <class Fun> y_combinator<std::decay_t<Fun>> make_y_combinator(Fun&& fun_) {
	return { std::forward<Fun>(fun_) };
};

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int N, M; cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; ++i) {
    int U, V; cin >> U >> V;
    --U, --V;
    E[U].push_back(V);
    E[V].push_back(U);
  }
  auto sub1 = [&]() -> void {
    int ans = int(1e9);
    vector<int> vis(N, 0), vis2(N, 0), vis3(N, 0);
    vector<vector<int>> q(2);
    int cnt = 0;
    auto dfs = make_y_combinator([&](auto &f, int u) -> void {
			++vis[u];
      ++vis3[u];
      for (auto v : E[u]) {
        if (!vis[v]) {
          f(v);
        }
      }
			q[0].push_back(u);
    });
		auto dfs2 = make_y_combinator([&](auto && f, int u) -> void {
			++vis2[u];
      ++vis3[u];
      for (auto v : E[u]) {
        if (!vis2[v]) {
          f(v);
        }
      }
			q[1].push_back(u);
    });
    auto dfs3 = make_y_combinator([&](auto && f, int u) -> void {
      ++vis3[u];
      for (auto v : E[u]) {
        if (!vis3[v]) {
          f(v);
        }
      }
      ++cnt;
    });
    auto work = [&](int x, int y) -> void {
      fill(vis.begin(), vis.end(), 0);
			fill(vis2.begin(), vis2.end(), 0);
      fill(vis3.begin(), vis3.end(), 0);
      q[0].clear();
      q[1].clear();
			vis[y] = 1;
      dfs(x);
			vis2[x] = 1;
      dfs2(y);
      bool can = true;
      vector<int> f;
      for (int i = 0; i < N; ++i) {
        if (i == x) {
					if (vis2[i] > 2) {
						can = false;
					}
				} else if (i == y) {
					if (vis[i] > 2) {
						can = false;
					}
				} else if (i != x && i != y) {
					if (vis[i] && vis2[i]) {
						can = false;
					}
				}
      }
      for (int i = 0; i < N; ++i) {
        if (!vis3[i]) {
          cnt = 0;
          dfs3(i);
          f.push_back(cnt);
        }
      }
      if (can) {
        int sum = 0;
        for (auto e : q[0]) {
          sum += int(E[e].size());
        }
        bool con = false;
        for (auto v : E[x]) {
          if (v == y) {
            con = true;
          }
        }
        sum -= (con ? 1 : 0);
        sum /= 2;
        int sum2 = 0;
        for (auto e : q[1]) {
          sum2 += int(E[e].size());
        }
        sum2 -= (con ? 1 : 0);
        sum2 /= 2;
        int x1 = int(q[0].size());
        int x2 = int(q[1].size());
        int r = x1 * (x1 - 1) / 2 + x2 * (x2 - 1) / 2;
        r -= sum;
        r -= sum2;
        int siz = int(f.size());
        sort(f.begin(), f.end());
        for (int i = 0; i < siz; ++i) {
          if (x1 < x2) {
            r += f[i] * x1;
            x1 += f[i];
          } else {
            r += f[i] * x2;
            x2 += f[i];
          }
        }
        ans = min(ans, r);
      }
    };
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        work(i, j);
      }
    }
    cout << (ans == int(1e9) ? -1 : ans) << "\n";
  };
	if (N <= 500) {
  	sub1();
	}

  return 0;
}

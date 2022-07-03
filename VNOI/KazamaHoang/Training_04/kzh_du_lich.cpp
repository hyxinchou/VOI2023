#include <bits/stdc++.h>

using i64 = long long;

template <class Fun> struct y_combinator {
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
	i64 K; cin >> K;
	vector<vector<int>> E(N);
	vector<int> A(N);
	for (auto &a : A) {
		cin >> a;
	}
	for (int i = 0; i < M; ++i) {
		int U, V; cin >> U >> V;
		--U, --V;
		assert(U >= 0 && U < N);
		assert(V >= 0 && V < N);
		E[U].push_back(V);
	}
	vector<int> col(N, 0);
	bool ok = false;
	auto dfs = make_y_combinator([&](auto && f, int u, int mx) -> void {
		col[u] = 1;
		for (auto v : E[u]) {
			if (A[v] > mx) {
				continue;
			}
			if (!col[v]) {
				f(v, mx);
			} else if (col[v] == 1) {
				ok = true;
			}
		}
		col[u] = 2;
	});
	vector<bool> vis(N, false);
	vector<int> p;
	auto dfs2 = make_y_combinator([&](auto && f, int u) -> void {
		vis[u] = true;
		for (auto v : E[u]) {
			if (!vis[v]) {
				f(v);
			}
		}
		p.push_back(u);
	});
	for (int i = 0; i < N; ++i) {
		if (!vis[i]) {
			dfs2(i);
		}
	}
	reverse(p.begin(), p.end());
	vector<int> dp(N, 0);
	int l = 0, r = *max_element(A.begin(), A.end()) + 1;
	while (r - l > 1) {
		fill(col.begin(), col.end(), 0);
		fill(dp.begin(), dp.end(), -1);
		ok = false;
		int m = (l + r) / 2;
		bool con = false;
		for (int i = 0; i < N; ++i) {
			if (A[i] <= m && !col[i]) {
				dfs(i, m);
			}
		}
		if (ok) {
			con = true;
		} else {
			for (int i = 0; i < int(p.size()); ++i) {
				if (A[p[i]] <= m) {
					dp[p[i]] = 0;
				}
			}
			for (int i = 0; i < int(p.size()); ++i) {
				if (A[p[i]] <= m) {
					for (auto v : E[p[i]]) {
						if (A[v] <= m) {
							dp[v] = max(dp[v], dp[p[i]] + 1);
						}
					}
				}
			}
			if (*max_element(dp.begin(), dp.end()) + 1 >= K) {
				con = true;
			}
		}
		if (con) {
			r = m;
		} else {
			l = m;
		}
	}
	bool ans = false;
	fill(col.begin(), col.end(), 0);
	fill(dp.begin(), dp.end(), -1);
	for (int i = 0; i < N; ++i) {
		if (A[i] <= r && !col[i]) {
			dfs(i, r);
		}
	}
	if (ok) {
		ans = true;
	}
	for (int i = 0; i < int(p.size()); ++i) {
		if (A[p[i]] <= r) {
			dp[p[i]] = 0;
		}
	}
	for (int i = 0; i < int(p.size()); ++i) {
		if (A[p[i]] <= r) {
			for (auto v : E[p[i]]) {
				if (A[v] <= r) {
					dp[v] = max(dp[v], dp[p[i]] + 1);
				}
			}
		}
	}
	if (*max_element(dp.begin(), dp.end()) + 1 >= K) {
		ans = true;
	}
	if (ans) {
		cout << r << "\n";
	} else {
		cout << "-1\n";
	}
	
	return 0;
}
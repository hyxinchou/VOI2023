#include <bits/stdc++.h>

namespace std {

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

} // namespace std;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M, D; cin >> N >> M >> D;
	vector<int> A(M);
	for (auto &v : A) {
		cin >> v;
		--v;
	}
	vector<vector<int>> E(N);
	for (int i = 0; i < N - 1; ++i) {
		int U, V; cin >> U >> V;
		--U, --V;
		E[U].push_back(V);
		E[V].push_back(U);
	}
	vector<int> d(N, 0);
	auto dfs = std::make_y_combinator([&](auto && f, int u, int p) -> void {
		for (auto v : E[u]) {
			if (v != p) {
				d[v] = d[u] + 1;
				f(v, u);
			}
		}
	});
	dfs(0, -1);
	int mx = -1;
	int node = 0;
	for (auto v : A) {
		if (mx < d[v]) {
			mx = d[v];
			node = v;
		}
	}
	// for (int i = 0; i < N; ++i) {
	// 	cout << d[i] << " ";
	// }
	// cout << "\n";
	fill(d.begin(), d.end(), 0);
	dfs(node, -1);
	int node2 = 0;
	mx = -1;
	for (auto v : A) {
		// cout << d[v] << " ";
		if (mx < d[v]) {
			mx = d[v];
			node2 = v;
		}
	}
	// cout << "\n";
	// for (int i = 0; i < N; ++i) {
	// 	cout << d[i] << " ";
	// }
	// cout << "\n";
	// cout << node << " " << node2 << "\n";
	vector<vector<int>> dd(2, vector<int> (N, 0));
	auto dfs2 = std::make_y_combinator([&](auto && f, int u, int p, int g) -> void {
		for (auto v : E[u]) {
			if (v != p) {
				dd[g][v] = dd[g][u] + 1;
				f(v, u, g);
			}
		}
	}) ;
	dfs2(node, -1, 0);
	dfs2(node2, -1, 1);
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (max(dd[0][i], dd[1][i]) <= D) {
			++ans;
		}
	}
	cout << ans << "\n";
	
	return 0;
}
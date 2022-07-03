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

	int N, M, S; cin >> N >> M >> S;
	vector<vector<int>> E(N);
	for (int i = 0; i < M; ++i) {
		int U, V; cin >> U >> V;
		--U, --V;
		E[U].push_back(V);
	}
	vector<int> vis(N, false);
	auto dfs = std::make_y_combinator([&](auto && f, int u) -> void {
		vis[u] = true;
		for (auto v : E[u]) {
			if (vis[v]) {
				continue;
			}
			f(v);
		}
	});
	dfs(S - 1);
	vector<int> path;
	for (int i = 0; i < N; ++i) {
		if (vis[i]) {
			path.push_back(i + 1);
		}
	}
	cout << int(path.size()) << "\n";
	for (auto v : path) {
		cout << v << " \n"[v == path.back()];
	}
	cout << "\n";
	
	return 0;
}
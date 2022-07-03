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

	constexpr int MOD = 1000000007;
	int N; cin >> N;
	vector<vector<int>>	E(N);
	for (int i = 0; i < N - 1; ++i) {
		int U, V; cin >> U >> V;
		--U, --V;
		E[U].push_back(V);
		E[V].push_back(U);
	}
	vector<vector<long long>> dp(N, vector<long long> (2, 0));
	auto dfs = std::make_y_combinator([&](auto && f, int u, int p) -> void {
		dp[u][0] = dp[u][1] = 1;
		for (auto v : E[u]) {
			if (v != p) {
				f(v, u);
				dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]);
				dp[u][0] %= MOD;
				dp[u][1] = dp[u][1] * dp[v][0];
				dp[u][1] %= MOD;
			}
		}
	});
	dfs(0, -1);
	cout << (dp[0][0] + dp[0][1]) % MOD << "\n";
	
	return 0;
}
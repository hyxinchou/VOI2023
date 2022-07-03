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

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<vector<int>> E(N);
		for (int i = 0; i < N - 1; ++i) {
			int U; cin >> U;
			--U;
			E[U].push_back(i + 1);
		}
		string S; cin >> S;
		vector<int> cnt(N, 0);
		vector<int> cnt2(N, 0);
		for (int i = 0; i < N; ++i) {
			S[i] == 'B' ? ++cnt[i] : ++cnt2[i];
		}
		auto dfs = std::make_y_combinator([&](auto && f, int u, int p) -> void {
			for (auto v : E[u]) {
				if (v != p) {
					f(v, u);
					cnt[u] += cnt[v];
					cnt2[u] += cnt2[v];
				}
			}
		});
		dfs(0, -1);
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			// cout << cnt[i] << " " << cnt2[i] << "\n";
			ans += cnt[i] == cnt2[i] ? 1 : 0;
		}
		cout << ans << "\n";
	}
	
	return 0;
}
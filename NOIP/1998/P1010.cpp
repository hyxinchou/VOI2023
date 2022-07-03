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

	vector<string> dp(20005, "");
	auto calc = std::make_y_combinator([&](auto && f, int v) -> string {
		if (dp[v] != "") {
			return dp[v];
		}
		string ans = "";
		for (int i = 20; ~i; --i) {
			if (v >> i & 1) {
				if (i == 0) {
					if (ans == "") {
						ans = "2(0)";
					} else {
						ans += "+2(0)";
					}
				} else if (i == 1) {
					if (ans == "") {
						ans = "2";
					} else {
						ans += "+2";
					}
				} else if (ans.empty()) {
					ans += "2(";
					ans += f(i);
					ans += ")";
				} else {
					ans += "+";
					ans += "2(";
					ans += f(i);
					ans += ")";
				}
			}
		}
		return dp[v] = ans;
	});
	int N; cin >> N;
	cout << calc(N) << "\n";
	
	return 0;
}
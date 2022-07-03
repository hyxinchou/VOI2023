#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	string M; cin >> M;
	auto add = [&](string ans, string s) -> string {
		while (int(ans.size()) < int(s.size())) {
			ans = '0' + ans;
		}
		while (int(ans.size()) > int(s.size())) {
			s = '0' + s;
		}
		reverse(ans.begin(), ans.end());
		reverse(s.begin(), s.end());
		int rm = 0;
		for (int i = 0; i < int(ans.size()); ++i) {
			int f = int(ans[i] - '0') + int(s[i] - '0') + rm;
			if (f >= N) {
				rm = f / N;
				f %= N;
			} else {
				rm = 0;
			}
			ans[i] = char(f + '0');
		}
		if (rm) {
			ans += '1';
		}
		reverse(ans.begin(), ans.end());
		return ans;
	};
	auto add2 = [&](string ans, string s) -> string {
		while (int(ans.size()) < int(s.size())) {
			ans = '0' + ans;
		}
		while (int(ans.size()) > int(s.size())) {
			s = '0' + s;
		}
		reverse(ans.begin(), ans.end());
		reverse(s.begin(), s.end());
		int rm = 0;
		for (int i = 0; i < int(ans.size()); ++i) {
			int f = (isdigit(ans[i]) ? int(ans[i] - '0') : (int(ans[i] - 'A') + 10)) + (isdigit(s[i]) ? int(s[i] - '0') : (int(s[i] - 'A') + 10)) + rm;
			if (f >= N) {
				rm = f / N;
				f %= N;
			} else {
				rm = 0;
			}
			if (f < 10) {
				ans[i] = char(f + '0');
			} else {
				ans[i] = char(f - 10 + 'A');
			}
		}
		if (rm) {
			if (rm >= 10) {
				ans += char(rm - 10 + 'A');
			} else {
				ans += char(rm + '0');
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	};
	// cout << add2("8AB", "B78") << "\n";
	if (N != 16) {
		int cnt = 0;
		while (cnt < 30) {
			auto f = M;
			reverse(f.begin(), f.end());
			M = add(M, f);
			f = M;
			reverse(f.begin(), f.end());
			if (M == f) {
				cout << "STEP=" << cnt + 1 << "\n";
				return 0;
			}
			++cnt;
		}
	} else {
		int cnt = 0;
		while (cnt < 30) {
			auto f = M;
			reverse(f.begin(), f.end());
			M = add2(M, f);
			f = M;
			reverse(f.begin(), f.end());
			if (M == f) {
				cout << "STEP=" << cnt + 1 << "\n";
				return 0;
			}
			++cnt;
		}
	}
	cout << "Impossible!\n";
	
	return 0;
}
#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	auto add = [&](string ans, string s) -> string {
		while (int(ans.size()) < int(s.size())) {
			ans = '0' + ans;
		}
		while (int(ans.size()) > int(s.size())) {
			s = '0' + ans;
		}
		reverse(ans.begin(), ans.end());
		reverse(s.begin(), s.end());
		int rm = 0;
		for (int i = 0; i < int(ans.size()); ++i) {
			int f = int(ans[i] - '0') + int(s[i] - '0') + rm;
			if (f >= 10) {
				f %= 10;
				rm = 1;
			} else {
				rm = 0;
			}
			ans[i] = char(f + '0');
		}
		if (rm) {
			ans.push_back('1');
		}
		reverse(ans.begin(), ans.end());
		return ans;
	};
	auto mul = [&](string ans, string s) -> string {
		vector<string> g;
		reverse(ans.begin(), ans.end());
		reverse(s.begin(), s.end());
		int rm = 0;
		for (int i = 0; i < int(ans.size()); ++i) {
			string r = string(i, '0');
			for (int j = 0; j < int(s.size()); ++j) {
				int f = int(ans[i] - '0') * int(s[j] - '0') + rm;
				if (f >= 10) {
					rm = f / 10;
					f %= 10;
				} else {
					rm = 0;
				}
				r += char(f + '0');
			}
			if (rm) {
				r += char(rm + '0');
				rm = 0;
			}
			reverse(r.begin(), r.end());
			g.push_back(r);
		}
		string fans = "";
		for (auto v : g) {
			fans = add(fans, v);
		}
		return fans;
	};
	int N; cin >> N;
	string ans = "1";
	vector<string> a;
	for (int i = 1; i <= N; ++i) {
		ans = mul(ans, to_string(i));
		a.push_back(ans);
	}
	ans = "";
	for (auto v : a) {
		ans = add(ans, v);
	}
	cout << ans << "\n";
	
	return 0;
}
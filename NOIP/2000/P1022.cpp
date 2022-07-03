#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	string S; cin >> S;
	string left = "";
	string right = "";
	bool change = false;
	char K;
	for (int i = 0; i < int(S.size()); ++i) {
		if (S[i] == '=') {
			change = true;
			continue;
		}
		if (!change) {
			left += S[i];
		} else {
			right += S[i];
		}
		if (isalpha(S[i])) {
			K = S[i];
		}
	}
	// cout << left << " " << right << "\n";
	auto calc = [&](string s) -> pair<int, int> {
		s += '+';
		string num = "";
		int Ca = 0;
		int tot = 0;
		char last = '+';
		if (s[0] == '-') {
			last = '-';
			s.erase(s.begin());
		}
		for (auto c : s) {
			if (c == '+' || c == '-') {
				// cout << num << " " << last << "\n";
				if (num.back() == K) {
					num.pop_back();
					if (num.empty()) {
						if (last == '+') {
							++Ca;
						} else {
							--Ca;
						}
					} else {
						int cv = 0;
						for (int i = 0; i < int(num.size()); ++i) {
							cv += pow(10, int(num.size()) - i - 1) * int(num[i] - '0');
						}
						if (last == '+') {
							Ca += cv;
						} else {
							Ca -= cv;
						}
					}
				} else {
					int cv = 0;
					for (int i = 0; i < int(num.size()); ++i) {
						cv += pow(10, int(num.size()) - i - 1) * int(num[i] - '0');
					}
					if (last == '+') {
						tot += cv;
					} else {
						tot -= cv;
					}
				}
				num = "";
				last = c;
			} else {
				num += c;
			}
		}
		return make_pair(Ca, tot);
	};
	auto [a, b] = calc(left);
	auto [x, y] = calc(right);
	// cout << a << " " << b << " " << x << " " << y << "\n";
	a -= x;
	y -= b;
	// cout << a << " " << y << "\n";
	cout << K << "=";
	// cout << 9 << "\n";
	if (!y) {
		cout << "0.000\n";
	} else {
		cout << setprecision(3) << fixed << double(double(y) / double(a)) << "\n";
	}
	
	return 0;
}
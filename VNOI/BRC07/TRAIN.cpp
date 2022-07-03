#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, L; cin >> N >> L;
	vector<int> X(N);
	for (auto &v : X) {
		cin >> v;
	}
	vector<int> T(N);
	for (auto &v : T) {
		cin >> v;
	}
	int loc = 0;
	long long ans = 0;
	bool b = true;
	for (int i = 0; i < N; ++i) {
		if (b) {
			if (X[i] >= loc) {
				ans += 1LL * abs(X[i] - loc) + T[i];
			} else {
				ans += abs(L - loc);
				loc = L;
				ans += 1LL * abs(X[i] - loc) + T[i];
				b = false;
			}
			loc = X[i];
		} else {
			if (X[i] <= loc) {
				ans += 1LL * abs(X[i] - loc) + T[i];
			} else {
				ans += loc;
				loc = 0;
				ans += 1LL * abs(X[i] - loc) + T[i];
				b = true;
			}
			loc = X[i];
		}
		// cout << loc << " ";
		if (b) {
			int nd = L - loc;
			if (T[i] <= nd) {
				loc += T[i];
			} else {
				int gg = T[i] - nd;
				int rm = gg % L;
				int tt = (gg - 1) / L + 1;
				if (tt & 1) {
					b = false;
					loc = L - rm;
				} else {
					loc = rm;
				}
			}
		} else {
			int nd = loc;
			if (T[i] <= nd) {
				loc -= T[i];
			} else {
				int gg = T[i] - nd;
				int rm = gg % L;
				int tt = (gg - 1) / L + 1;
				if (tt & 1) {
					b = true;
					loc = rm;
				} else {
					loc = L - rm;
				}
			}
		}
		// cout << loc << " ";
		if (b) {
			if (X[i] >= loc) {
				ans += 1LL * abs(X[i] - loc);
			} else {
				ans += abs(L - loc);
				loc = L;
				ans += 1LL * abs(X[i] - loc);
				b = false;
			}
			loc = X[i];
		} else {
			if (X[i] <= loc) {
				ans += 1LL * abs(X[i] - loc);
			} else {
				ans += loc;
				loc = 0;
				ans += 1LL * abs(X[i] - loc);
				b = true;
			}
			loc = X[i];
		}
		// cout << ans << " " << loc << "\n";
	}
	if (b) {
		ans += 1LL * 2 * L - loc;
	} else {
		ans += 1LL * loc;
	}
	cout << ans << "\n";
	
	return 0;
}
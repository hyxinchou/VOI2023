#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N);
		for (auto &v : A) {
			cin >> v;
		}
		vector<int> B(N);
		for (auto &v : B) {
			cin >> v;
		}
		vector<int> diff(N);
		int mx = 0;
		bool hv = false;
		for (int i = 0; i < N; ++i) {
			diff[i] = A[i] - B[i];
			if (B[i]) {
				hv = true;
				mx = diff[i];
			}
		}
		bool ok = true;
		// cout << "hv :: " << hv << " ";
		if (hv) {
			for (int i = 0; i < N; ++i) {
				if (!B[i]) {
					ok = diff[i] > mx ? false : ok;
				} else if (B[i]) {
					ok = diff[i] != mx ? false : ok;
				}
			}
		}
		ok = mx < 0 ? false : ok;
		cout << (ok ? "YES" : "NO") << "\n";
	}	
	
	return 0;
}
#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		if (N % 3 == 0) {
			cout << N / 3 << " " << N / 3 + 1 << " " << N / 3 - 1 << "\n";
		} else if (N % 3 == 1) {
			cout << N / 3 << " " << N / 3 + 2 << " " << N / 3 - 1 << "\n";
		} else if (N % 3 == 2) {
			cout << N / 3 + 1 << " " << N / 3 + 2 << " " << N / 3 - 1 << "\n";
		}
	}
	
	return 0;
}
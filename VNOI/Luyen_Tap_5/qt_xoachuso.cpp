#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	int ans = 0;
	while (N) {
		int mx = 0;
		int C = N;
		while (C) {
			mx = max(mx, C % 10);
			C /= 10;
		}
		N -= mx;
		++ans;
	}
	cout << ans << "\n";
	
	return 0;
}
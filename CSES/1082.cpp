#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	long long n; cin >> n;
	long long ans = 0;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			if (i != n / i) {
				ans += 1LL * i + 1LL * n / i;
			} else {
				ans += 1LL * i;
			}
		}
	}
	cout << ans << "\n";
	
	return 0;
}
#include <bits/stdc++.h>

using i64 = long long;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	i64 N; cin >> N;
	i64 ans = 0;
	while (N >= 2) {
		ans += N / 2;
		N /= 2;
	}
	cout << ans << "\n";
	
	return 0;
}
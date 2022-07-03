#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	constexpr int MOD = 1000000007;
	int T; cin >> T;
	while (T--) {
		int A, B; cin >> A >> B;
		auto Pow = [&](long long a, int b) -> int {
			long long r = 1;
			while (b) {
				if (b & 1) {
					r *= a;
					r %= MOD;
				}
				a *= a;
				a %= MOD;
				b /= 2;
			}
			return r;
		};
		cout << Pow(A, B) << "\n";
	}
	
	return 0;
}
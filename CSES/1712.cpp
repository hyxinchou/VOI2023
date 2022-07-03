#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	constexpr int MOD = 1000000007;
	int T; cin >> T;
	while (T--) {
		int A, B, C; cin >> A >> B >> C;
		auto Pow = [&](long long a, int b, int P) -> int {
			long long r = 1;
			while (b) {
				if (b & 1) {
					r *= a;
					r %= P;
				}
				a *= a;
				a %= P;
				b /= 2;
			}
			return r;
		};
		cout << Pow(A, Pow(B, C, MOD - 1), MOD) << "\n";
	}
		
	return 0;
}
template<typename T>
struct Binom {
	constexpr int P, n;
	std::vectot<T> fac, invfac;
	Binom(int n, int P) : n(n), P(P), fac(2 * n), invfac(2 * n) {
		auto Pow = [&](T a, T b) -> T {
			T ans = 1;
			while (b) {
				if (b & 1) {
					ans *= a;
					ans %= P;
				}
				a *= a;
				a %= P;
				b /= 2;
			}
			return ans;
		};
		fac[0] = 1;
		for (int i = 1; i <= n; ++i) {
			fac[i] = (fac[i - 1] * i) % P;
		}
		invfac[200000] = Pow(fac[200000], P - 2);
		for (int i = 200000; i > 0; --i) {
			invfac[i - 1] = (invfac[i] * i) % P;
		}
	}
	T nCr(int a, int b) {
		T ans = (((fac[a] * invfac[a - b]) % MOD) * invfac[b]) % MOD;
		return ans;
	}
};

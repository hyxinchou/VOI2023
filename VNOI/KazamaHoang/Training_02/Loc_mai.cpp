#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, K; cin >> N >> K;
	vector<int> A(N);
	for (auto &v : A) {
		cin >> v;
	}
	int nums = 0;
	vector<bool> nA;
	set<int> Unique2;
	for (auto v : A) {
		bool lucky = true;
		int C = v;
		while (C) {
			lucky = C % 10 != 2 && C % 10 != 6 ? false : lucky;
			C /= 10;
		}
		if (lucky) {
			Unique2.insert(v);
		}
		nums += lucky ? 1 : 0;
		nA.push_back(lucky);
	}
	auto sub1 = [&]() -> void {
		int ans = 0;
		for (int mask = 0; mask < (1 << N); ++mask) {
			if (__builtin_popcount(mask) != K) {
				continue;
			}
			set<int> Unique;
			int add = 0;
			for (int i = 0; i < N; ++i) {
				if (mask >> i & 1) {
					if (nA[i]) {
						Unique.insert(A[i]);
						++add;
					}
				}
			}
			if (add == int(Unique.size())) {
				++ans;
			}
		}
		cout << ans << "\n";
	};
	constexpr int MOD = 1000000007;
	#define i64 long long
	vector<i64> fac(100005), invfac(100005);
	fac[0] = 1;
	for (int i = 1; i <= 100000; ++i) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= MOD;
	}
	auto pow = [&](i64 a, int b) -> i64 {
		i64 r = 1;
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
	invfac[100000] = pow(fac[100000], MOD - 2);
	for (int i = 100000; i; --i) {
		invfac[i - 1] = invfac[i] * i;
		invfac[i - 1] %= MOD;
	}
	auto binom = [&](int n, int r) -> i64 {
		if (n < r) {
			return 0;
		}
		return (((fac[n] * invfac[n - r]) % MOD) * invfac[r]) % MOD;
	};
	vector<int> Unique;
	map<int, int> mp;
	int num = 0;
	for (int i = 0; i < N; ++i) {
		if (nA[i]) {
			Unique.push_back(A[i]);
			++mp[A[i]];
		} else {
			++num;
		}
	}
	sort(Unique.begin(), Unique.end());
	Unique.erase(unique(Unique.begin(), Unique.end()), Unique.end());
	int len = int(Unique.size());
	auto sub2 = [&]() -> void {	
		i64 ans = 0;
		for (int mask = 0; mask < (1 << len); ++mask) {
			i64 ways = 1;
			for (int i = 0; i < len; ++i) {
				if (mask >> i & 1) {
					ways *= 1LL * mp[Unique[i]];
				}
			}
			i64 on = __builtin_popcount(mask);
			ways %= MOD;
			if (K - on >= 0) {
				ans += ways * binom(num, K - on);
			}
			ans %= MOD;
		}
		cout << ans << "\n";
	};
	auto sub4 = [&]() -> void {
		vector<i64> dp(K + 1, -1);
		dp[0] = 1;
		for (int i = 0; i < len; ++i) {
			for (int j = K; ~j; --j) {
				if (dp[j] != -1 && j + 1 <= K) {
					if (dp[j + 1] == -1) {
						dp[j + 1] = 0;
					}
					dp[j + 1] += dp[j] * mp[Unique[i]];
					dp[j + 1] %= MOD;
				}
			}
		}
		i64 ans = 0;
		for (int i = 0; i <= K; ++i) {
			if (dp[i] != -1) {
				ans += dp[i] * binom(num, K - i);
				ans %= MOD;
			}
		}
		cout << ans << "\n";
	};
	if (N <= 20) {
		sub1();
	} else if (N <= 2000 && nums <= 10) {
		sub2();
	} else if (int(Unique2.size()) <= 5) {
		sub2();
	} else {
		sub4();
	}
	
	return 0;
}

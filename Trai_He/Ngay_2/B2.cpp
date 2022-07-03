#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    constexpr int MOD = int(1e9) + 7;
    std::vector<i64> fac(N + 2, 0), invfac(N + 2, 0);
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= MOD;
    }
    auto pow = [&](i64 a, i64 b) -> i64 {
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
    invfac[N] = pow(fac[N], MOD - 2);
    for (int i = N; i > 0; --i) {
        invfac[i - 1] = invfac[i] * i;
        invfac[i - 1] %= MOD;
    }
    auto nCr = [&](int a, int b) -> i64 {
        if (b > a) {
            return i64(0);
        }
        i64 ans = (((fac[a] * invfac[a - b]) % MOD) * invfac[b]) % MOD;
        return ans;
    };
    i64 ans = 1;
    for (i64 i = 2; i <= N; i += 2) {
        i64 r = ((fac[i] * invfac[i / 2]) % MOD * pow(pow(2, i / 2), MOD - 2)) % MOD;
        ans += nCr(N, i) * (r * r % MOD);
        ans %= MOD;
    }
    std::cout << ans << "\n";

    return 0;
}

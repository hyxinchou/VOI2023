#include <bits/stdc++.h>

using i64 = long long;

int N, M, K, X, Q, T, L, R, D;
i64 a[10000005], Prefix[10000005], Suffix[10000005];

int main() {
    std::cin >> N >> M >> K >> X >> Q >> T;
    a[0] = X;
    for (int i = 1; i < N; ++i) {
        a[i] = (a[i - 1] * K) % M;
    }
    for (int i = 0; i < N; ++i) {
        a[i] -= Q;
    }
    Prefix[0] = -i64(1e18);
    for (int i = 0; i < N; ++i) {
        Prefix[i + 1] = std::max(a[i], Prefix[i]);
    }
    Suffix[N + 1] = -i64(1e18);
    for (int i = N - 1; i >= 0; --i) {
        Suffix[i + 1] = std::max(a[i], Suffix[i + 2]);
    }
    while (T--) {
        std::cin >> L >> R >> D;
        std::cout << std::max({Prefix[L - 1], Suffix[R + 1], Prefix[R] - D}) << "\n";
    }
    return 0;
}
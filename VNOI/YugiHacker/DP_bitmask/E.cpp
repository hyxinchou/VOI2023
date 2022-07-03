#include <bits/stdc++.h>

using i64 = long long;

int N, A[30][30], dp[1 << 21];
i64 ways[1 << 21];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> A[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    memset(ways, 0, sizeof(ways));
    ways[0] = 1;
    for (int mask = 0; mask < (1 << N); ++mask) {
        for (int i = 0; i < N; ++i) {
            if (mask >> i & 1) {
                int j = __builtin_popcount(mask);
                if (dp[mask] < dp[mask ^ (1 << i)] + A[i][j - 1]) {
                    dp[mask] = dp[mask ^ (1 << i)] + A[i][j - 1];
                    ways[mask] = ways[mask ^ (1 << i)];
                } else if (dp[mask] == dp[mask ^ (1 << i)] + A[i][j - 1]) {
                    ways[mask] += ways[mask ^ (1 << i)];
                }
            }
        }
    }
    std::cout << dp[(1 << N) - 1] << " " << ways[(1 << N) - 1] << "\n";


    return 0;
}

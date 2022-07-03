#include <bits/stdc++.h>

using i64 = long long;

int N, K, S[20];
i64 dp[1 << 20][20], answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        std::cin >> S[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; ++i) {
        dp[1 << i][i] = 1;
    }
    for (int mask = 0; mask < (1 << N); ++mask) {
        for (int i = 0; i < N; ++i) {
            if (mask >> i & 1) {
                for (int j = 0; j < N; ++j) {
                    if (!(mask >> j & 1)) {
                        if (std::abs(S[i] - S[j]) > K) {
                            dp[mask | (1 << j)][j] += dp[mask][i];
                        }
                    }
                }
            }
        }
    }
    answer = 0;
    for (int i = 0; i < N; ++i) {
        answer += dp[(1 << N) - 1][i];
    }
    std::cout << answer << "\n";

    return 0;
}

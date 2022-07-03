#include <bits/stdc++.h>

using i64 = long long;

int M, B[2005], SEQ198 = (1 << 1) | (1 << 8) | (1 << 9), dp[2005][1 << 10], answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        std::cin >> B[i];
    }
    std::sort(B, B + M);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < M; ++i) {
        for (int mask = 0; mask < (1 << 10); ++mask) {
            if (dp[i - 1][mask] >= 0) {
                int new_mask = (B[i] - B[i - 1] >= 10 ? 0 : mask << (B[i] - B[i - 1]) & ((1 << 10) - 1));
                dp[i][new_mask] = std::max(dp[i][new_mask], dp[i - 1][mask]);
                if ((new_mask & SEQ198) == 0) {
                    dp[i][new_mask | 1] = std::max(dp[i][new_mask | 1], dp[i - 1][mask] + 1);
                }
            }
        }
    }
    answer = 0;
    for (int mask = 0; mask < (1 << 10); ++mask) {
        answer = std::max(answer, dp[M - 1][mask]);
    }
    std::cout << M - answer << "\n";

    return 0;
}

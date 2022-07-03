#include <bits/stdc++.h>

using i64 = long long;

int N, C[20][20], dp[1 << 20][20], answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> C[i][j];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < N; ++i) {
        dp[0][i] = 0;
    }
    for (int mask = 0; mask < (1 << N); ++mask) {
        for (int i = 0; i < N; ++i) {
            if (!mask || mask >> i & 1) {
                for (int j = 0; j < N; ++j) {
                    if (!(mask >> j & 1)) {
                        dp[mask | (1 << j)][j] = std::min(dp[mask | (1 << j)][j], dp[mask][i] + C[i][j]);
                    }
                }
            }
        }
    }
    answer = int(1e9);
    for (int i = 0; i < N; ++i) {
        answer = std::min(answer, dp[(1 << N) - 1][i]);
    }
    std::cout << answer << "\n";

    return 0;
}

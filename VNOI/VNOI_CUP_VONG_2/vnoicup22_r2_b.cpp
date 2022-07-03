#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<std::vector<int>> A(N, std::vector<int> (M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> A[i][j];
        }
    }

    auto sub2 = [&]() -> void {
        std::vector<std::vector<i64>> dp(N + 2, std::vector<i64> (K + 1, 0));
        i64 ans = 0;
        for (int i = 0; i < N; ++i) {
            i64 sum = 0;
            for (int j = 0; j <= M; ++j) {
                sum += 1LL * (j ? A[i][j - 1] : 0);
                for (int k = 0; k <= K; ++k) {
                    if (k >= j) {
                        dp[i + 1][k] = std::max(dp[i + 1][k], dp[i][k - j] + sum);
                        ans = std::max(ans, dp[i + 1][k]);
                    }
                }
            }
        }
        std::cout << ans << "\n";
    };

    auto sub3 = [&]() -> void {
        std::vector<std::vector<std::pair<i64, int>>> dp(N + 2, std::vector<std::pair<i64, int>> (M + 1, std::make_pair(0, 0)));
        i64 sum = 0;
        for (int i = 0; i <= M; ++i) {
            sum += 1LL * (i ? A[0][i - 1] : 0);
            dp[1][i] = std::make_pair(sum, i);
            std::cerr << dp[1][i].first << " \n"[i == M];
        }
        i64 ans = 0;
        for (int i = 1; i < N; ++i) {
            i64 sum = 0;
            for (int j = 0; j <= M; ++j) {
                sum += 1LL * (j ? A[i][j - 1] : 0);
                for (int k = 0; k <= M; ++k) {
                    auto [x, y] = dp[i][k];
                    if (j + y <= K) {
                        auto [x2, y2] = dp[i + 1][j];
                        if (x + sum > x2) {
                            dp[i + 1][j] = std::make_pair(x + sum, j + y);
                        } else if (x + sum == x2 && j + y < y2) {
                            dp[i + 1][j] = std::make_pair(x + sum, j + y);
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= M; ++j) {
                // ans = std::max(ans, dp[i][j].first);
                std::cerr << i << " " << j << " " << dp[i][j].first << " " << dp[i][j].second << "\n";
            }
        }
        std::cout << ans << "\n";
    };

    sub3();

    return 0;
}

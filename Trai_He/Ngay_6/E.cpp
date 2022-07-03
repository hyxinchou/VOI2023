#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("antiqueen.inp", "r", stdin);
    freopen("antiqueen.out", "w", stdout);

    int R, C, N;
    std::cin >> R >> C >> N;
    constexpr int MOD = 998244353;
    std::vector<std::vector<i64>> dp(R, std::vector<i64> (C, 1));
    i64 ans = 0;
    for (int step = 0; step < N; ++step) {
        i64 Sum = 0;
        std::vector<int> Row(R);
        std::vector<int> Col(C);
        for (int i = 0; i < R; ++i) {
            i64 sum = 0;
            for (int j = 0; j < C; ++j) {
                sum += dp[i][j];
                sum %= MOD;
            }
            Row[i] = sum;
        }
        for (int i = 0; i < C; ++i) {
            i64 sum = 0;
            for (int j = 0; j < R; ++j) {
                sum += dp[j][i];
                sum %= MOD;
            }
            Col[i] = sum;
        }
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                Sum += dp[i][j];
                Sum %= MOD;
            }
        }
        std::vector<std::vector<int>> F(R, std::vector<int> (C, 0));
        for (int i = 0; i < R; ++i) {
            i64 sum = 0;
            for (int j = 0; j < C && j + i < R; ++j) {
                sum += dp[i + j][j];
                sum %= MOD;
            }
            F[i][0] = sum;
        }
        for (int i = 0; i < C; ++i) {
            i64 sum = 0;
            for (int j = 0; j < R && i + j < C; ++j) {
                sum += dp[j][i + j];
                sum %= MOD;
            }
            F[0][i] = sum;
        }
        std::vector<std::vector<int>> F2(R, std::vector<int> (C, 0));
        for (int i = C - 1; i >= 0; --i) {
            i64 sum = 0;
            for (int j = 0; j < R && i - j >= 0; ++j) {
                sum += dp[j][i - j];
                sum %= MOD;
            }
            F2[0][i] = sum;
        }
        for (int i = 0; i < R; ++i) {
            i64 sum = 0;
            for (int j = C - 1; j >= 0 && i + (C - 1 - j) < R; --j) {
                sum += dp[i + (C - 1 - j)][j];
                sum %= MOD;
            }
            F2[i][C - 1] = sum;
        }
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                dp[i][j] = Sum - Row[i] - Col[j] - F[i - std::min(i, j)][j - std::min(i, j)] - F2[i - std::min(i, C - 1 - j)][j + std::min(i, C - 1 - j)] + 3 * dp[i][j];
                dp[i][j] %= MOD;
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            ans += dp[i][j];
            ans %= MOD;
        }
    }
    std::cout << ans << "\n";

    return 0;
}

#include <bits/stdc++.h>

using i64 = long long;

int N, A[3][100005], dp[100005][3];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> A[j][i];
        }
    }
    dp[0][0] = A[0][0];
    dp[0][1] = A[1][0];
    dp[0][2] = A[2][0];
    for (int i = 1; i < N; ++i) {
        dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][2]) + A[0][i];
        dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][2]) + A[1][i];
        dp[i][2] = std::max(dp[i - 1][0], dp[i - 1][1]) + A[2][i];
    }
    std::cout << std::max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]}) << "\n";

    return 0;
}

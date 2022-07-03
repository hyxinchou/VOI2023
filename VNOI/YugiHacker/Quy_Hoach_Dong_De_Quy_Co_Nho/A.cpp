#include <bits/stdc++.h>

using i64 = long long;

int N, H[100005], dp[100005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }
    std::memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    dp[1] = std::abs(H[1] - H[0]);
    for (int i = 2; i < N; ++i) {
        dp[i] = std::min(dp[i - 1] + std::abs(H[i - 1] - H[i]), dp[i - 2] + std::abs(H[i - 2] - H[i]));
    }
    std::cout << dp[N - 1] << "\n";

    return 0;
}

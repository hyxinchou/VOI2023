#include <bits/stdc++.h>

using i64 = long long;

int N, K, H[100005], dp[100005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }
    std::memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= std::min(i, K); ++j) {
            dp[i] = std::min(dp[i], dp[i - j] + std::abs(H[i] - H[i - j]));
        }
    }
    std::cout << dp[N - 1] << "\n";

    return 0;
}

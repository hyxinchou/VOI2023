#include <bits/stdc++.h>

using i64 = long long;

int N, W, w[105], v[105];
i64 dp[100005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> W;
    for (int i = 0; i < N; ++i) {
        std::cin >> w[i] >> v[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = W; j >= 0; --j) {
            if (j >= w[i]) {
                dp[j] = std::max(dp[j], dp[j - w[i]] + 1LL * v[i]);
            }
        }
    }
    std::cout << *std::max_element(dp, dp + 100005) << "\n";

    return 0;
}

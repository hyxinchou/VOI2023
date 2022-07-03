#include <bits/stdc++.h>

using i64 = long long;

int N, W, w[105], v[105], answer;
i64 dp[100005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> W;
    for (int i = 0; i < N; ++i) {
        std::cin >> w[i] >> v[i];
    }
    answer = 0;
    std::memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 100000; j >= 0; --j) {
            if (j >= v[i]) {
                dp[j] = std::min(dp[j], dp[j - v[i]] + w[i]);
                if (dp[j] <= W) {
                    answer = std::max(answer, j);
                }
            }
        }
    }
    std::cout << answer << "\n";

    return 0;
}

#include <bits/stdc++.h>

using i64 = long long;

int N, M;
i64 dp[35][1 << 6], answer;

void solve() {
    std::cin >> N >> M;
    if (N > M) {
        std::swap(N, M);
    }
    memset(dp, 0, sizeof(dp));
    for (int mask = 0; mask < (1 << N); ++mask) {
        dp[0][mask] = 1;
    }
    for (int i = 1; i < M; ++i) {
        for (int mask = 0; mask < (1 << N); ++mask) {
            for (int mask2 = 0; mask2 < (1 << N); ++mask2) {
                bool can = true;
                for (int j = 0; j < N - 1; ++j) {
                    if (mask >> j & 1 && mask >> (j + 1) & 1 && mask2 >> j & 1 && mask2 >> (j + 1) & 1) {
                        can = false;
                    }
                    if (!(mask >> j & 1) && !(mask >> (j + 1) & 1) && !(mask2 >> j & 1) && !(mask2 >> (j + 1) & 1)) {
                        can = false;
                    }
                }
                if (can) {
                    dp[i][mask] += dp[i - 1][mask2];
                }
            }
        }
    }
    answer = 0;
    for (int mask = 0; mask < (1 << N); ++mask) {
        answer += dp[M - 1][mask];
    }
    std::cout << answer << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Tests;
    std::cin >> Tests;
    while (Tests--) {
        solve();
    }

    return 0;
}

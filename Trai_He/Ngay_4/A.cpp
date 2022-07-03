#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    constexpr int P = int(1e9) + 7;
    std::map<int, std::map<int, i64>> dp;
    std::vector<i64> ans(1000005, 0);
    for (int i = 0; i < N; ++i) {
        ++dp[A[i]][1];
        for (int j = 2; j < 32; ++j) {
            if (A[i] % Q == 0 && dp[A[i] / Q][j - 1]) {
                dp[A[i]][j] += dp[A[i] / Q][j - 1];
                dp[A[i]][j] %= P;
                ans[j] += dp[A[i] / Q][j - 1];
                ans[j] %= P;
            } else {
                break;
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        std::cout << ans[i] << " \n"[i == N];
    }



    return 0;
}

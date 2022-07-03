#include <bits/stdc++.h>

using i64 = long long;

int N, A[1000005], dp[1000005];
bool on[1000005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    std::memset(on, true, sizeof(on));
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        on[A[i]] = false;
        dp[A[i]] = std::max(dp[A[i]], 1);
        for (int j = 2 * A[i]; j <= N; j += A[i]) {
            if (on[j]) {
                dp[j] = std::max(dp[j], dp[A[i]] + 1);
            }
        }
    }
    std::cout << *std::max_element(dp, dp + N + 1) << "\n";

    return 0;
}

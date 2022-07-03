#include <bits/stdc++.h>

using i64 = long long;

int N, A[1005], dp[1005];
std::map<int, int> C;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        ++C[A[i]];
    }
    std::sort(A, A + N);
    std::memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            --C[A[i]];
            --C[A[j]];
            if (C[A[j] - A[i]]) {
                dp[j] = std::max(dp[j], dp[i] + 1);
            }
            ++C[A[i]];
            ++C[A[j]];
        }
    }
    std::cout << *std::max_element(dp, dp + N) + 1 << "\n";
    
    return 0;
}
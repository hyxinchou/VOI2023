#include <bits/stdc++.h>

using i64 = long long;

int N, A[1005];
std::vector<int> dp;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        int l = std::lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        if (l < int(dp.size())) {
            dp[l] = A[i];
        } else {
            dp.push_back(A[i]);
        }
    }
    std::cout << int(dp.size()) << "\n";

    return 0;
}

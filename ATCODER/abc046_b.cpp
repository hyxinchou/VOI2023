#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;
    i64 ans = K;
    for (int i = 1; i < N; ++i) {
        ans *= (K - 1);
    }
    std::cout << ans << "\n";

    return 0;
}

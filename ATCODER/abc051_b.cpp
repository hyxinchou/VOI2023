#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int K, S;
    std::cin >> K >> S;
    int ans = 0;
    for (int X = 0; X <= K; ++X) {
        for (int Y = 0; Y <= K; ++Y) {
            int Z = S - X - Y;
            if (Z <= K && Z >= 0) {
                ++ans;
            }
        }
    }
    std::cout << ans << "\n";

    return 0;
}

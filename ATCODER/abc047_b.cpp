#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int W, H, N;
    std::cin >> W >> H >> N;
    int ml = 0, mr = W, mu = 0, md = H;
    for (int i = 0; i < N; ++i) {
        int x, y, a;
        std::cin >> x >> y >> a;
        if (a == 1) {
            ml = std::max(ml, x);
        } else if (a == 2) {
            mr = std::min(mr, x);
        } else if (a == 3) {
            mu = std::max(mu, y);
        } else {
            md = std::min(md, y);
        }
    }
    std::cout << std::max(0, mr - ml) * std::max(0, md - mu) << "\n";

    return 0;
}

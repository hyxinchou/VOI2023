#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;
    while (Q--) {
        int i, j, x, y;
        std::cin >> i >> j >> x >> y;
        if (i == x && j == y) {
            std::cout << "0\n";
        } else if ((std::abs(i - x) + std::abs(j - y)) & 1) {
            std::cout << "-1\n";
        } else {
            if (std::abs(i - x) == std::abs(y - j)) {
                std::cout << "1\n";
                std::cout << x << " " << y << "\n";
            } else {
                std::cout << "2\n";
                bool ok = false;
                for (int ii = 1; ii <= N; ++ii) {
                    for (int jj = 1; jj <= N; ++jj) {
                        if (std::abs(i - ii) == std::abs(j - jj) && std::abs(ii - x) == std::abs(jj - y)) {
                            std::cout << ii << " " << jj << "\n";
                            ok = true;
                            break;
                        }
                    }
                    if (ok) {
                        break;
                    }
                }
                std::cout << x << " " << y << "\n";
            }
        }
    }

    return 0;
}

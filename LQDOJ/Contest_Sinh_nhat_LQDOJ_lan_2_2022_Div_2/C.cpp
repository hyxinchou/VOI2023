#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 D, T, B;
    std::cin >> D >> T >> B;
    i64 min = T;
    i64 max = B * T;
    i64 diff = B - 1;
    if (D >= min && D <= max && (D - min) % diff == 0) {
        std::cout << "Possible\n";
    } else {
        std::cout << "Impossible\n";
    }

    return 0;
}

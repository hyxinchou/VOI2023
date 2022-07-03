#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 a, b, x;
    std::cin >> a >> b >> x;
    i64 aa = (a + x - 1) / x * x;
    if (aa > b) {
        std::cout << "0\n";
    } else {
        std::cout << (b - aa) / x + 1 << "\n";
    }

    return 0;
}

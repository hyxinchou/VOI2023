#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;
    std::cout << std::string(tx - sx, 'R') << std::string(ty - sy, 'U') << std::string(tx - sx, 'L') << std::string(ty - sy, 'D');
    std::cout << 'D' << std::string(tx - sx + 1, 'R') << std::string(ty - sy + 1, 'U') << "LU" << std::string(tx - sx + 1, 'L') << std::string(ty - sy + 1, 'D') << "R\n";

    return 0;
}

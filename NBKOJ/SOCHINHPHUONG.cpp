#include <bits/stdc++.h>

using i64 = long long;

int T;
long double num;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> T;
    while (T--) {
        std::cin >> num;
        if (std::sqrt(num) == std::floor(std::sqrt(num))) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    
    return 0;
}
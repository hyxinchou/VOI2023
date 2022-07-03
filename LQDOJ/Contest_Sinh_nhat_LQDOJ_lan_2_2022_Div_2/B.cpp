#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    std::cin >> S;
    int n = int(S.size());
    int ans = 1;
        for (int i = 1; i <= n / 2; ++i) {
        std::string a = S.substr(0, i);
        std::string b = S.substr(i, i);
        if (a == b) {
            ans = std::max(ans, i);
        }
    }
    std::cout << 2 * ans << "\n";

    return 0;
}

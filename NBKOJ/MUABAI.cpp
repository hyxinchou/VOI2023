#include <bits/stdc++.h>

using i64 = long long;

i64 C, P, N1, N2, T1, T2;

void solve() {
    std::cin >> C >> P >> N1 >> N2 >> T1 >> T2;
    i64 l = -1, r = C + 1;
    while (r - l > 1) {
        i64 m = (l + r) / 2;
        if (m * P + T1 * i64(m / N1) + T2 * i64(m / N2) <= C) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << l << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int Tests;
    std::cin >> Tests;
    while (Tests--) {
        solve();
    }
    
    return 0;
}
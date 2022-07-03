#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::set<std::array<int, 3>> A;
    for (int i = 0; i < N; ++i) {
        int l, r;
        std::cin >> l >> r;
        A.insert({l, r, i});
    }
    for (auto [l, r, i] : A) {
        auto it = A.upper_bound({r + 1, -1, -1});
        if (it != A.end() && (*it)[2] != i) {
            std::cout << "YES\n";
            std::cout << std::min(i, (*it)[2]) + 1 << " " << std::max(i, (*it)[2]) + 1 << "\n";
            return 0;
        }
    }
    std::cout << "NO\n";

    return 0;
}

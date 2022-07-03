#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<std::array<int, 3>> A(N);
    for (auto &[x, y, z] : A) {
        std::cin >> x >> y >> z;
        assert(z > 0);
    }
    std::map<int, std::map<int, std::map<int, int>>> C;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        auto [a, b, c] = A[i];
        C.clear();
        int add = 0;
        int r = 0;
        for (int j = 0; j < N; ++j) {
            auto [a2, b2, c2] = A[j];
            if (a == a2 && b == b2 && c == c2) {
                ++add;
            }
            if (i != j) {
                int da = a - a2;
                int db = b - b2;
                int dc = c - c2;
                if (dc > 0) {
                    int g = std::__gcd(da, std::__gcd(db, dc));
                    ++C[da / g][db / g][dc / g];
                    r = std::max(r, C[da / g][db / g][dc / g]);
                }
            }
        }
        ans = std::max(ans, r + add);
    }
    std::cout << ans << "\n";

    return 0;
}

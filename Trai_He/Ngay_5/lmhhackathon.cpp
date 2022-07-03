#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int M, N, P;
    std::cin >> M >> N >> P;
    std::vector<std::array<i64, 3>> W(M + N + P);
    std::vector<std::array<i64, 3>> W2;
    for (auto &[a, b, c] : W) {
        std::cin >> a >> b >> c;
        a -= c;
        b -= c;
        W2.push_back({a, b, a - b});
    }
    std::sort(W2.begin(), W2.end(), [&](const auto &lhs, const auto &rhs) {
        return lhs[2] < rhs[2];
    });
    std::vector<i64> Prefix = {0};
    std::multiset<i64> Set;
    i64 sum = 0;
    for (int i = 0; i < M; ++i) {
        Set.insert(W2[i][0]);
        sum += W2[i][0];
        Prefix.push_back(sum);
    }
    for (int i = M; i < M + N + P; ++i) {
        Set.insert(W2[i][0]);
        i64 del = *Set.rbegin();
        sum -= del;
        sum += W2[i][0];
        Set.erase(Set.find(del));
        Prefix.push_back(sum);
    }
    std::vector<i64> Suffix;
    Set.clear();
    sum = 0;
    for (int i = N + M + P - 1;  i >= M + P; --i) {
        Set.insert(W2[i][1]);
        sum += W2[i][1];
        Suffix.push_back(sum);
    }
    /*
    3 3 3
    1 2 3
    2 5 4
    4 6 5
    1 7 4
    6 9 7
    8 6 5
    4 7 9
    7 5 4
    3 6 4
    */
    for (int i = M + P - 1; ~i; --i) {
        Set.insert(W2[i][1]);
        i64 del = *Set.rbegin();
        sum -= del;
        sum += W2[i][1];
        Set.erase(Set.find(del));
        Suffix.push_back(sum);
    }
    Suffix.push_back(0);
    std::reverse(Suffix.begin(), Suffix.end());
    i64 ans = i64(1e18);
    for (int i = M; i <= M + P; ++i) {
        ans = std::min(ans, Prefix[i] + Suffix[i + 1]);
    }
    for (auto [a, b, c] : W) {
        ans += c;
    }
    std::cout << ans << "\n";

    return 0;
}

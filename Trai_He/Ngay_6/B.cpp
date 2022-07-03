#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("couples.inp", "r", stdin);
    freopen("couples.out", "w", stdout);

    int subtask;
    std::cin >> subtask;
    std::vector<std::pair<int, int>> S, S2, S3, S4;
    int M;
    std::cin >> M;
    std::vector<int> B(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> B[i];
        if (B[i] > 0) {
            S.push_back(std::make_pair(B[i], i));
        } else {
            S2.push_back(std::make_pair(-B[i], i));
        }
    }
    int F;
    std::cin >> F;
    std::vector<int> G(F);
    for (int i = 0; i < F; ++i) {
        std::cin >> G[i];
        if (G[i] > 0) {
            S3.push_back(std::make_pair(G[i], i));
        } else {
            S4.push_back(std::make_pair(-G[i], i));
        }
    }
    std::sort(S.begin(), S.end());
    std::sort(S2.begin(), S2.end());
    std::sort(S3.begin(), S3.end());
    std::sort(S4.begin(), S4.end());
    int ans = 0;
    std::vector<std::pair<int, int>> path;
    for (int i = 0, j = 0; i < int(S.size()); ++i) {
        while (j < int(S4.size()) && S4[j].first <= S[i].first) {
            ++j;
        }
        if (j < int(S4.size())) {
            ++ans;
            path.push_back(std::make_pair(S[i].second, S4[j].second));
            ++j;
        }
    }
    for (int i = 0, j = 0; i < int(S3.size()); ++i) {
        while (j < int(S2.size()) && S2[j].first <= S3[i].first) {
            ++j;
        }
        if (j < int(S2.size())) {
            ++ans;
            path.push_back(std::make_pair(S2[j].second, S3[i].second));
            ++j;
        }
    }
    std::cout << ans << "\n";
    for (auto [u, v] : path) {
        std::cout << u + 1 << " " << v + 1 << "\n";
    }

    return 0;
}

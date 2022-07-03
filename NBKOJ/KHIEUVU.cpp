#include <bits/stdc++.h>

using i64 = long long;

int N, M, B[100005], G[100005], Q;
i64 X, Y, answer;

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }
    for (int i = 0; i < M; ++i) {
        std::cin >> G[i];
    }
    std::sort(B, B + N, [&](const auto &x, const auto &y) {
        return x > y;
    });
    std::sort(G, G + M);
    std::cin >> Q;
    for (int i = 0; i < Q; ++i) {
        std::cin >> X >> Y;
        answer = 0;
        for (int i = 0, l = 0, r = 0; i < N; ++i) {
            while (l < M && 1LL * B[i] * G[l] < X) {
                ++l;
            }
            while (r < M && 1LL * B[i] * G[r] <= Y) {
                ++r;
            }
            if (r > l) {
                answer += 1LL * (r - l);
            }
            // std::cout << i << " " << l << " " << r << "\n";
        }
        std::cout << answer << "\n";
    }
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
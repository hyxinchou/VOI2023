#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("covid19.inp", "r", stdin);
    freopen("covid19.out", "w", stdout);

    int T;
    std::cin >> T;
    int N, K, Q;
    std::cin >> N >> K >> Q;
    std::vector<int> F0(K);
    for (int i = 0; i < K; ++i) {
        std::cin >> F0[i];
        --F0[i];
    }
    std::vector<std::pair<char, std::pair<int, int>>> queries;
    for (int i = 0; i < Q; ++i) {
        char C;
        std::cin >> C;
        int U, V;
        std::cin >> U >> V;
        --U, --V;
        queries.push_back(std::make_pair(C, std::make_pair(U, V)));
    }
    constexpr int MOD = 998244353;
    std::vector<i64> n(N + 1);
    n[0] = 1;
    for (int i = 1; i <= N; ++i) {
        n[i] = n[i - 1] * (N + 1);
        n[i] %= MOD;
    }

    auto sub1 = [&]() -> void {
        i64 ans = 0;
        for (int i = 0; i < N; ++i) {
            ans -= n[i + 1];
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
        }
        for (int i = 0; i <= Q; ++i) {
            std::cout << ans << "\n";
        }
    };

    auto sub2 = [&]() -> void {
        std::vector<int> F(N, N);
        for (int i = 0; i < K; ++i) {
            F[F0[i]] = 0;
        }
        i64 ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += (F[i] == N ? -1 : F[i]) * n[i + 1];
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
        }
        std::cout << ans << "\n";
        for (int i = 0; i < Q; ++i) {
            auto [u, v] = queries[i].second;
            int min = std::min(F[u], F[v]);
            if (F[u] > min + 1) {
                ans -= (F[u] == N ? -1 : F[u]) * n[u + 1];
                ans %= MOD;
                ans += MOD;
                ans %= MOD;
                F[u] = min + 1;
                ans += F[u] * n[u + 1];
                ans %= MOD;
            }
            if (F[v] > min + 1) {
                ans -= (F[v] == N ? -1 : F[v]) * n[v + 1];
                ans %= MOD;
                ans += MOD;
                ans %= MOD;
                F[v] = min + 1;
                ans += F[v] * n[v + 1];
                ans %= MOD;
            }
            std::cout << ans << "\n";
        }
    };

    auto sub3 = [&]() -> void {
        std::vector<int> F(N, N);
        for (int i = 0; i < K; ++i) {
            F[F0[i]] = 0;
        }
        i64 ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += (F[i] == N ? -1 : F[i]) * n[i + 1];
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
        }
        std::cout << ans << "\n";
        for (int i = 0; i < Q; ++i) {
            if (queries[i].first == 'D') {
                auto [u, v] = queries[i].second;
                int min = std::min(F[u], F[v]);
                if (F[u] > min + 1) {
                    ans -= (F[u] == N ? -1 : F[u]) * n[u + 1];
                    ans %= MOD;
                    ans += MOD;
                    ans %= MOD;
                    F[u] = min + 1;
                    ans += F[u] * n[u + 1];
                    ans %= MOD;
                }
                if (F[v] > min + 1) {
                    ans -= (F[v] == N ? -1 : F[v]) * n[v + 1];
                    ans %= MOD;
                    ans += MOD;
                    ans %= MOD;
                    F[v] = min + 1;
                    ans += F[v] * n[v + 1];
                    ans %= MOD;
                }
            } else {
                auto [u, v] = queries[i].second;
                int min = int(1e9);
                for (int j = u; j <= v; ++j) {
                    min = std::min(min, F[j]);
                }
                for (int j = u; j <= v; ++j) {
                    if(F[j] == min && j        )
                    if (F[j] > min + 1) {
                        ans -= (F[j] == N ? -1 : F[j]) * n[j + 1];
                        ans %= MOD;
                        ans += MOD;
                        ans %= MOD;
                        F[j] = min + 1;
                        ans += F[j] * n[j + 1];
                        ans %= MOD;
                    }
                }
            }
            std::cout << ans << "\n";
        }
    };

    if (T == 1) {
        sub1();
    } else if (T == 2) {
        sub2();
    } else if (T == 3) {
        sub3();
    }

    return 0;
}

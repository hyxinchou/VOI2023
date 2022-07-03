#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> f;
    DSU(int n) : f(n) {
        std::iota(f.begin(), f.end(), 0);
    }
    int leader(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        f[y] = x;
        return true;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("mmgraph.inp", "r", stdin);
    freopen("mmgraph.out", "w", stdout);

    int subtask;
    std::cin >> subtask;
    int N, M;
    std::cin >> N >> M;
    std::vector<int> W(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> W[i];
    }
    std::vector<std::array<int, 3>> E;
    for (int i = 0; i < M; ++i) {
        int F, T, C;
        std::cin >> F >> T >> C;
        --F, --T;
        E.push_back({F, T, C});
    }

    auto sub1 = [&]() -> void {
        for (int i = 0; i < N; ++i) {
            std::cout << N - 1 << " \n"[i == N - 1];
        }
    };

    auto sub2 = [&]() -> void {
        std::sort(E.begin(), E.end(), [&](const auto &x, const auto &y) {
            return x[2] < y[2];
        });
        std::vector<std::vector<i64>> d(N, std::vector<i64> (N, 0));
        DSU dsu(N);
        std::vector<std::vector<std::pair<i64, int>>> edges(N);
        for (auto [u, v, c] : E) {
            if (dsu.merge(u, v)) {
                edges[u].push_back(std::make_pair(c, v));
                edges[v].push_back(std::make_pair(c, u));
            }
        }
        auto dfs = [&](auto &f, int u, int p, int root, i64 cost) -> void {
            for (auto [c, v] : edges[u]) {
                if (v != p) {
                    cost = std::max(cost, c);
                    d[root][v] = cost;
                    f(f, v, u, root, cost);
                }
            }
        };
        for (int i = 0; i < N; ++i) {
            dfs(dfs, i, -1, i, 0);
        }
        for (int i = 0; i < N; ++i) {
            i64 ans = 0;
            for (int j = 0; j < N; ++j) {
                ans += d[i][j];
            }
            std::cout << ans << " \n"[i == N - 1];
        }
    };

    auto sub3 = [&]() -> void {
        std::vector<std::array<int, 3>> E2;
        for (auto [u, v, c] : E) {
            E2.push_back({u, v, std::max(W[u], W[v])});
        }
        std::sort(E2.begin(), E2.end(), [&](const auto &x, const auto &y) {
            return x[2] < y[2];
        });
        std::vector<std::vector<i64>> d(N, std::vector<i64> (N, 0));
        DSU dsu(N);
        std::vector<std::vector<std::pair<i64, int>>> edges(N);
        for (auto [u, v, c] : E2) {
            if (dsu.merge(u, v)) {
                edges[u].push_back(std::make_pair(c, v));
                edges[v].push_back(std::make_pair(c, u));
            }
        }
        auto dfs = [&](auto &f, int u, int p, int root, i64 cost) -> void {
            for (auto [c, v] : edges[u]) {
                if (v != p) {
                    cost = std::max(cost, c);
                    d[root][v] = cost;
                    f(f, v, u, root, cost);
                }
            }
        };
        for (int i = 0; i < N; ++i) {
            dfs(dfs, i, -1, i, 0);
        }
        for (int i = 0; i < N; ++i) {
            i64 ans = 0;
            for (int j = 0; j < N; ++j) {
                ans += d[i][j];
            }
            std::cout << ans << " \n"[i == N - 1];
        }
    };

    auto sub5 = [&]() -> void {
        std::vector<int> Unq;
        for (int i = 0; i < N; ++i) {
            Unq.push_back(W[i]);
        }
        std::sort(Unq.begin(), Unq.end());
        Unq.erase(std::unique(Unq.begin(), Unq.end()), Unq.end());
        std::vector<std::vector<i64>> d(N, std::vector<i64> (N, i64(1e18)));
        for (int i = 0; i < N; ++i) {
            d[i][i] = 0;
        }
        std::sort(E.begin(), E.end(), [&](const auto &x, const auto &y) {
            return x[2] < y[2];
        });
        for (auto lim : Unq) {
            std::vector<std::array<int, 3>> E2;
            for (auto [u, v, c] : E) {
                if (std::max(W[u], W[v]) <= lim) {
                    E2.push_back({u, v, c});
                }
            }
            std::vector<std::vector<std::pair<int, int>>> edges(N);
            DSU dsu(N);
            for (auto [u, v, c] : E2) {
                if (dsu.merge(u, v)) {
                    edges[u].push_back(std::make_pair(c, v));
                    edges[v].push_back(std::make_pair(c, u));
                }
            }
            for (int i = 0; i < N; ++i) {
                std::vector<std::vector<int>> d2(N, std::vector<int> (N, int(1e9)));
                auto dfs = [&](auto &f, int u, int p, int root, int val) -> void {
                    for (auto [c, v] : edges[u]) {
                        if (v != p) {
                            val = std::max(val, c);
                            d2[root][v] = val;
                            f(f, v, u, root, val);
                        }
                    }
                };
                dfs(dfs, i, -1, i, 0);
                for (int j = 0; j < N; ++j) {
                    if (d2[i][j] != int(1e9)) {
                        d[i][j] = std::min(d[i][j], 1LL * d2[i][j] * lim);
                    }
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            i64 ans = 0;
            for (int j = 0; j < N; ++j) {
                ans += d[i][j];
            }
            std::cout << ans << " \n"[i == N - 1];
        }
    };

    if (subtask == 1) {
        sub1();
    } else if (subtask == 2) {
        sub2();
    } else if (subtask == 3) {
        sub3();
    } else {
        sub5();
    }

    return 0;
}

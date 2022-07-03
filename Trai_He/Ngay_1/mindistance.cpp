#include <bits/stdc++.h>

using i64 = long long;

int LOG = 20;
struct LCA {
    const int n;
    std::vector<int> d;
    std::vector<std::vector<int>> up, E;
    LCA(int n) : n(n) {
        d = std::vector<int> (n, 0);
        E = std::vector<std::vector<int>> (n);
        up = std::vector<std::vector<int>> (n, std::vector<int> (LOG, 0));
    }
    void add_edges(int u, int v) {
        E[u].push_back(v);
        E[v].push_back(u);
    }
    void dfs_lca(int u, int p) {
        for (auto v : E[u]) {
            if (v != p) {
                d[v] = d[u] + 1;
                up[v][0] = u;
                for (int i = 1; i < LOG; ++i) {
                    up[v][i] = up[up[v][i - 1]][i - 1];
                }
                dfs_lca(v, u);
            }
        }
    }
    int lca(int u, int v) {
        if (d[u] < d[v]) {
            std::swap(u, v);
        }
        int diff = d[u] - d[v];
        for (int i = LOG - 1; ~i; --i) {
            if (diff >> i & 1) {
                u = up[u][i];
            }
        }
        if (u == v) {
            return u;
        }
        for (int i = LOG - 1; ~i; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
    int k_th(int u, int k) {
        if (d[u] < k) {
            return -1;
        }
        for (int i = LOG - 1; ~i; --i) {
            if (k >> i & 1) {
                u = up[u][i];
            }
        }
        return u;
    }
};

template <class Fun>
struct y_combinator {
    Fun fun_;
    template <class... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_((*this), std::forward<Args>(args)...);
    }
};
template <class Fun> y_combinator<std::decay_t<Fun>> make_y_combinator(Fun&& fun_) {
    return { std::forward<Fun>(fun_) };
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::vector<int>> E(N);
    LCA lca(N);
    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        std::cin >> U >> V;
        --U, --V;
        E[U].push_back(V);
        E[V].push_back(U);
        lca.add_edges(U, V);
    }

    auto sub1 = [&]() -> void {
        std::vector<bool> col(N, false);
        for (int i = 0; i < Q; ++i) {
            int T, V;
            std::cin >> T >> V;
            --V;
            if (T == 1) {
                col[V] = !col[V];
            } else {
                int ans = int(1e9);
                auto dfs = make_y_combinator([&](auto && f, int u, int p, int d) -> void {
                    if (col[u]) {
                        ans = std::min(ans, d);
                    }
                    for (auto v : E[u]) {
                        if (v != p) {
                            f(v, u, d + 1);
                        }
                    }
                });
                dfs(V, -1, 0);
                if (ans == int(1e9)) {
                    ans = -1;
                }
                std::cout << ans << "\n";
            }
        }
    };

    auto sub2 = [&]() -> void {
        lca.dfs_lca(0, -1);
        std::unordered_map<int, int, custom_hash> C;
        for (int i = 0; i < Q; ++i) {
            int T, V;
            std::cin >> T >> V;
            --V;
            if (T == 1) {
                if (C.count(V)) {
                    C.erase(V);
                } else {
                    C[V] = 1;
                }
            } else {
                int ans = int(1e9);
                for (auto [v, f] : C) {
                    ans = std::min(ans, lca.d[V] + lca.d[v] - 2 * lca.d[lca.lca(V, v)]);
                }
                if (ans == int(1e9)) {
                    ans = -1;
                }
                std::cout << ans << "\n";
            }
        }
    };

    if (N <= 5000 && Q <= 5000) {
        sub1();
    } else {
        sub2();
    }

    return 0;
}

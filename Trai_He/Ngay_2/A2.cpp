#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) {
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
    int size(int x) {
        return siz[leader(x)];
    }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;
    DSU d(N);
    std::vector<std::pair<int, int>> E;
    for (int i = 0; i < Q; ++i) {
        int U, V, C;
        std::cin >> U >> V >> C;
        --U, --V;
        if (!C) {
            d.merge(U, V);
        } else {
            E.push_back(std::make_pair(U, V));
        }
    }
    int max = 0;
    std::vector<int> all;
    for (auto [u, v] : E) {
        all.push_back(d.leader(u));
        all.push_back(d.leader(v));
        max = std::max({max, d.leader(u), d.leader(v)});
    }
    std::vector<std::vector<int>> edges(max + 1);
    std::sort(all.begin(), all.end());
    all.erase(std::unique(all.begin(), all.end()), all.end());
    for (auto [u, v] : E) {
        edges[d.leader(u)].push_back(d.leader(v));
        edges[d.leader(v)].push_back(d.leader(u));
    }
    std::vector<int> col(N, -1);
    bool ok = true;
    auto dfs = make_y_combinator([&](auto && f, int u, int p) -> void {
        for (auto v : edges[u]) {
            if (v != p) {
                if (col[v] == col[u]) {
                    ok = false;
                } else {
                    col[v] = col[u] ^ 1;
                }
                f(v, u);
            }
        }
    });
    for (auto v : all) {
        if (col[v] == -1) {
            col[v] = 1;
            dfs(v, -1);
        }
    }
    if (!ok) {
        std::cout << "-1\n";
    } else {
        for (int i = 0; i < N; ++i) {
            if (col[d.leader(i)] == -1) {
                std::cout << "1 ";
            } else {
                std::cout << col[d.leader(i)] + 1 << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}

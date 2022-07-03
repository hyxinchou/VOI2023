#include <bits/stdc++.h>

using i64 = long long;

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

    int N, K;
    std::cin >> N >> K;
    std::vector<std::vector<int>> E(N);
    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        std::cin >> U >> V;
        --U, --V;
        E[U].push_back(V);
        E[V].push_back(U);
    }
    std::vector<int> siz(N, 0);
    auto dfs = make_y_combinator([&](auto && f, int u, int p) -> int {
        siz[u] = 1;
        for (auto v : E[u]) {
            if (v != p) {
                siz[v] += f(v, u);
            }
        }
        return siz[u];
    });
    dfs(0, -1);
    auto get_centroid = make_y_combinator([&](auto && f, int u, int p) -> int {
        for (auto v : E[u]) {
            if (v != p) {
                if (siz[v] > n / 2) {
                    return f(v, u);
                }
            }
        }
        return u;
    });
    

    return 0;
}

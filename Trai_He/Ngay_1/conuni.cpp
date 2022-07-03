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
    std::vector<int> U(2 * K);
    std::vector<int> Z(N);
    for (int i = 0; i < 2 * K; ++i) {
        std::cin >> U[i];
        --U[i];
        Z[U[i]] = i;
    }
    std::vector<std::vector<int>> E(N);
    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        std::cin >> U >> V;
        --U, --V;
        E[U].push_back(V);
        E[V].push_back(U);
    }
    std::vector<std::vector<int>> d(2 * K, std::vector<int> (N, 0));
    auto dfs = make_y_combinator([&](auto && f, int u, int p, int id) -> void {
        for (auto v : E[u]) {
            if (v != p) {
                d[id][v] = d[id][u] + 1;
                f(v, u, id);
            }
        }
    });
    for (int i = 0; i < 2 * K; ++i) {
        dfs(U[i], -1, i);
    }
    std::vector<int> p(2 * K);
    std::iota(p.begin(), p.end(), 0);
    int ans = 0;
    do {
        int r = 0;
        for (int i = 0; i < 2 * K; i += 2) {
            r += d[Z[U[p[i]]]][U[p[i + 1]]];
        }
        ans = std::max(ans, r);
    } while (std::next_permutation(p.begin(), p.end()));
    std::cout << ans << "\n";

    return 0;
}

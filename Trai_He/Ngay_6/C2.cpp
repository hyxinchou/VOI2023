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

i64 d2[505][505];
int N, M, W[505], d[505];
std::vector<std::array<int, 3>> E;
std::vector<int> Unq;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("mmgraph.inp", "r", stdin);
    freopen("mmgraph.out", "w", stdout);

    int subtask;
    std::cin >> subtask;
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        std::cin >> W[i];
        Unq.push_back(W[i]);
    }
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        --u, --v;
        E.push_back({u, v, c});
    }
    std::sort(E.begin(), E.end(), [&](const auto &x, const auto &y) {
        return x[2] < y[2];
    });
    std::sort(Unq.begin(), Unq.end());
    Unq.erase(std::unique(Unq.begin(), Unq.end()), Unq.end());
    std::memset(d2, 0x3f3f, sizeof(d2));
    for (int i = 0; i < N; ++i) {
        d2[i][i] = 0;
    }
    for (int i = 0; i < int(Unq.size()); ++i) {
        int lim = Unq[i];
        DSU dsu(N);
        std::vector<std::vector<std::pair<int, int>>> edges(N);
        for (int j = 0; j < M; ++j) {
            if (std::max(W[E[j][0]], W[E[j][1]]) <= lim) {
                if (dsu.merge(E[j][0], E[j][1])) {
                    edges[E[j][0]].push_back(std::make_pair(E[j][2], E[j][1]));
                    edges[E[j][1]].push_back(std::make_pair(E[j][2], E[j][0]));
                }
            }
        }
        std::function<void(int, int, int, int)> dfs = [&](int u, int p, int root, int cost) {
            for (int j = 0; j < int(edges[u].size()); ++j) {
                if (edges[u][j].second != p) {
                    cost = std::max(cost, edges[u][j].first);
                    d[edges[u][j].second] = cost;
                    dfs(edges[u][j].second, u, root, cost);
                }
            }
        };
        for (int j = 0; j < N; ++j) {
            std::memset(d, 0, sizeof(d));
            dfs(j, -1, j, 0);
            for (int k = 0; k < N; ++k) {
                if (d[k]) {
                    d2[j][k] = std::min(d2[j][k], 1LL * d[k] * lim);
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        i64 sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += d2[i][j];
        }
        std::cout << sum << " \n"[i == N - 1];
    }

    return 0;
}

#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> f;
    std::vector<std::set<int>> siz;
    DSU(int n) : f(n), siz(n) {
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
        if (int(siz[x].size()) > int(siz[y].size())) {
            std::swap(x, y);
        }
        while (!siz[x].empty()) {
            siz[y].insert(*siz[x].begin());
            siz[x].erase(*siz[x].begin());
        }
        f[x] = y;
        return true;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, C, Q;
    std::cin >> N >> M >> C >> Q;
    std::vector<std::vector<std::pair<int, int>>> E(N);
    bool f = true;
    for (int i = 0; i < M; ++i) {
        int X, Y, Z;
        std::cin >> X >> Y >> Z;
        --X, --Y;
        E[X].push_back(std::make_pair(Y, Z));
        E[Y].push_back(std::make_pair(X, Z));
        f = (Z != 1 ? false : f);
    }
    std::vector<std::array<int, 4>> queries;
    for (int i = 0; i < Q; ++i) {
        char O;
        std::cin >> O;
        if (O == '+') {
            int X, Y, Z;
            std::cin >> X >> Y >> Z;
            --X, --Y;
            queries.push_back({0, X, Y, Z});
            f = (Z != 1 ? false : f);
        } else {
            int X, Y;
            std::cin >> X >> Y;
            --X, --Y;
            queries.push_back({1, X, Y, -1});
        }
    }

    auto sub1 = [&]() -> void {
        DSU d(N);
        for (int u = 0; u < N; ++u) {
            for (auto [v, c] : E[u]) {
                d.merge(u, v);
            }
        }
        for (auto [o, x, y, z] : queries) {
            if (!o) {
                d.merge(x, y);
            } else {
                std::cout << (d.same(x, y) ? "Yes" : "No") << "\n";
            }
        }
    };

    auto sub2 = [&]() -> void {
        DSU d(N);
        std::map<int, std::map<int, std::vector<int>>> q;
        std::vector<std::set<int>> Unq(N);
        for (int u = 0; u < N; ++u) {
            for (auto [v, c] : E[u]) {
                q[u][c].push_back(v);
                Unq[u].insert(c);
            }
        }
        for (int i = 0; i < N; ++i) {
            for (auto c : Unq[i]) {
                for (int j = 0; j < int(q[i][c].size()) - 1; ++j) {
                    d.merge(q[i][c][j], q[i][c][j + 1]);
                }
            }
        }
        for (auto [o, x, y, z] : queries) {
            if (!o) {
                if (!q[x][z].empty()) {
                    d.merge(q[x][z][0], y);
                }
                if (!q[y][z].empty()) {
                    d.merge(q[y][z][0], x);
                }
                q[x][z].push_back(y);
                q[y][z].push_back(x);
            } else {
                std::cout << (d.same(x, y) ? "Yes" : "No") << "\n";
            }
        }
    };

    auto sub3 = [&]() -> void {
        DSU d(N);
        std::map<int, std::map<int, int>> q;
        for (int u = 0; u < N; ++u) {
            for (auto [v, c] : E[u]) {
                d.siz[d.leader(u)].insert(v);
                if (q[u].count(c)) {
                    d.merge(q[u][c], v);
                }
                q[u][c] = v;
            }
        }
        for (auto [o, x, y, z] : queries) {
            if (!o) {
                d.siz[d.leader(x)].insert(y);
                d.siz[d.leader(y)].insert(x);
                if (q[x].count(z)) {
                    d.merge(q[x][z], y);
                }
                if (q[y].count(z)) {
                    d.merge(q[y][z], x);
                }
                q[x][z] = y;
                q[y][z] = x;
            } else {
                std::cout << (d.same(x, y) || d.siz[d.leader(x)].count(y) ? "Yes" : "No") << "\n";
            }
        }
    };

    sub3();

    return 0;
}

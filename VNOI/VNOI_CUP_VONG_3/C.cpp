#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    if (N == 2 && M == 1) {
        int u, v, x, y;
        std::cin >> u >> v >> x >> y;
        std::cout << x << " " << y << "\n";
    } else if (N <= 6) {
        std::vector<std::array<int, 4>> A(M);
        std::vector<std::vector<int>> f(N);
        for (auto &[u, v, x, y] : A) {
            std::cin >> u >> v >> x >> y;
            --u, --v;
            if (!f[u].size()) {
                f[u].push_back(x);
                f[u].push_back(y);
            }
            if (!f[v].size()) {
                f[v].push_back(x);
                f[v].push_back(y);
            }
        }
        for (int i = 0; i < (1 << N); ++i) {
            std::vector<int> h(N, -1);
            for (int j = 0; j < N; ++j) {
                if (i >> j & 1) {
                    if (f[j].size()) {
                        h[j] = std::max(f[j][0], f[j][1]);
                    } else {
                        h[j] = 1;
                    }
                } else {
                    if (f[j].size()) {
                        h[j] = std::min(f[j][0], f[j][1]);
                    } else {
                        h[j] = 1;
                    }
                }
            }
            bool ok = true;
            for (auto [u, v, x, y] : A) {
                if (h[u] == x && h[v] == y) {
                    continue;
                }
                if (h[u] == y && h[v] == x) {
                    continue;
                }
                ok = false;
            }
            if (ok) {
                for (int j = 0; j < N; ++j) {
                    std::cout << h[j] << " \n"[j == N - 1];
                }
                return 0;
            }
        }
        std::cout << "-1\n";
    } else {
        bool ok = true;
        std::vector<std::array<int, 4>> A(M);
        std::map<int, std::map<int, int>> C;
        std::map<int, std::map<int, std::map<int, std::map<int, int>>>> G;
        std::vector<int> h(N, -1);
        for (auto &[u, v, x, y] : A) {
            std::cin >> u >> v >> x >> y;
            --u, --v;
            if (G[u][v][x][y]) {
                continue;
            }
            G[u][v][x][y] = 1;
            G[v][u][x][y] = 1;
            ++C[u][x];
            ++C[u][y];
            if (C[u][x] >= 2) {
                if (h[u] == -1) {
                    h[u] = x;
                } else if (h[u] != x) {
                    ok = false;
                }
            }
            if (C[u][y] >= 2) {
                if (h[u] == -1) {
                    h[u] = y;
                } else if (h[u] != y) {
                    ok = false;
                }
            }
            ++C[v][x];
            ++C[v][y];
            if (C[v][x] >= 2) {
                if (h[v] == -1) {
                    h[v] = x;
                } else if (h[v] != x) {
                    ok = false;
                }
            }
            if (C[v][y] >= 2) {
                if (h[v] == -1) {
                    h[v] = y;
                } else if (h[v] != y) {
                    ok = false;
                }
            }
        }
        for (auto [u, v, x, y] : A) {
            if (h[u] != -1) {
                if (h[v] == -1) {
                    h[v] = (h[u] == x ? y : x);
                }
            }
            if (h[v] != -1) {
                if (h[u] == -1) {
                    h[u] = (h[v] == x ? y : x);
                }
            }
            if (h[u] == -1 && h[v] == -1) {
                h[u] = x;
                h[v] = y;
            }
        }
        for (int i = 0; i < N; ++i) {
            if (h[i] == -1) {
                h[i] = 1;
            }
        }
        for (auto [u, v, x, y] : A) {
            if (h[u] == x && h[v] == y) {
                continue;
            }
            if (h[v] == x && h[u] == y) {
                continue;
            }
            ok = false;
        }
        if (!ok) {
            std::cout << "-1\n";
        } else {
            for (int i = 0; i < N; ++i) {
                std::cout << h[i] << " \n"[i == N - 1];
            }
        }
    }

    return 0;
}

#include <bits/stdc++.h>

using i64 = long long;

int N, U, V, C, P[4], d[105][105], E[105][105], answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for (int i = 0; i < 4; ++i) {
        std::cin >> P[i];
        --P[i];
    }
    std::memset(E, 0x3f3f, sizeof(E));
    for (int i = 0; i < N; ++i) {
        E[i][i] = 0;
    }
    while (std::cin >> U >> V >> C) {
        --U, --V;
        E[U][V] = std::min(E[U][V], C);
        E[V][U] = std::min(E[V][U], C);
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (E[i][k] != 0x3f3f && E[k][j] != 0x3f3f) {
                    E[i][j] = std::min(E[i][j], E[i][k] + E[k][j]);
                }
            }
        }
    }
    answer = 1E9;
    std::vector<int> p(4);
    std::iota(p.begin(), p.end(), 0);
    do {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int r = E[P[p[0]]][i] + E[i][P[p[1]]] + E[P[p[2]]][j] + E[j][P[p[3]]] + E[i][j];
                answer = std::min(answer, r);
            }
        }
    } while (std::next_permutation(p.begin(), p.end()));
    std::cout << answer << "\n";

    return 0;
}

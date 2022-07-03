#include <bits/stdc++.h>

using i64 = long long;

int P, N, C, A, B, F[505], E[505][505], min_dist, answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> P >> N >> C;
    for (int i = 0; i < N; ++i) {
        std::cin >> F[i];
        --F[i];
    }
    memset(E, 0x3f3f, sizeof(E));
    for (int i = 0; i < P; ++i) {
        E[i][i] = 0;
    }
    for (int i = 0; i < C; ++i) {
        std::cin >> A >> B;
        --A, --B;
        std::cin >> E[A][B];
        E[B][A] = E[A][B];
    }
    for (int k = 0; k < P; ++k) {
        for (int i = 0; i < P; ++i) {
            for (int j = 0; j < P; ++j) {
                if (E[i][k] != 0x3f3f && E[k][j] != 0x3f3f) {
                    E[i][j] = std::min(E[i][j], E[i][k] + E[k][j]);
                }
            }
        }
    }
    min_dist = 1E9;
    for (int i = 0; i < P; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += E[i][F[j]];
        }
        if (sum < min_dist) {
            min_dist = sum;
            answer = i;
        }
    }
    std::cout << answer + 1 << "\n";

    return 0;
}

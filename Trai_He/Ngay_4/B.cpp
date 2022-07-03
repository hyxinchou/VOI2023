#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::vector<std::vector<i64>> A(N, std::vector<i64> (N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cin >> A[i][j];
            }
        }
        std::vector<std::vector<i64>> B = A;
        std::vector<std::vector<i64>> C(N, std::vector<i64> (N, 0));
        auto empty_ = C;
        auto mul = [&]() -> void {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (int k = 0; k < N; ++k) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        };
        mul();
        A = C;
        C = empty_;
        mul();
        std::vector<std::vector<i64>> D(N, std::vector<i64> (N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cin >> D[i][j];
            }
        }
        if (C == D) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}

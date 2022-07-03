#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::srand(std::time(NULL));
    auto gen = [&](int L, int R) -> int {
        return L + (std::rand() % (R - L + 1));
    };
    int N = gen(1, 50);
    int M = gen(1, int(25e5));
    std::cout << N + 1 << " " << M + 1 << "\n";
    for (int i = 0; i < N; ++i) {
        int L = gen(1, 5000);
        std::cout << L + 1 << "\n";
        for (int j = 0; j < L; ++j) {
            std::cout << gen(-1000, 1000) << " \n"[i == L - 1];
        }
    }
    for (int i = 0; i < M; ++i) {
        std::cout << gen(1, N) << " \n"[i == M - 1];
    }

    return 0;
}

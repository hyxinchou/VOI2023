#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, Q;
    std::cin >> N >> M >> Q;
    std::vector<std::bitset<100000>> F(N);
    for (int i = 0; i < M; ++i) {
        int U, V;
        std::cin >> U >> V;
        --U, --V;
        F[U][V] = 1;
        F[V][U] = 1;
    }
    while (Q--) {
        char O;
        std::cin >> O;
        if (O == '+') {
            int U, V;
            std::cin >> U >> V;
            --U, --V;
            F[U][V] = 1;
            F[V][U] = 1;
        } else {
            int U, V;
            std::cin >> U >> V;
            --U, --V;
            if ((F[U] & F[V]).any()) {
                std::cout << "1";
            } else {
                std::cout << "0";
            }
        }
    }

    return 0;
}

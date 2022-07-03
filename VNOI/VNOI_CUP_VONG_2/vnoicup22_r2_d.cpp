#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    int Q;
    std::cin >> Q;

    auto sub1 = [&]() -> void {
        while (Q--) {
            int l, r;
            std::cin >> l >> r;
            --l, --r;
            std::vector<int> C(N + 1, 0);
            std::set<int> Unq;
            bool ans = true;
            int max = 0;
            for (int i = l; i <= r; ++i) {
                ++C[A[i]];
                // max = std::max(max, C[A[i]]);
                Unq.insert(A[i]);
            }
            for (auto v : Unq) {
                if (C[v] != K) {
                    ans = false;
                    max = v;
                }
            }
            if (ans) {
                std::cout << "0\n";
            } else {
                std::cout << max << "\n";
            }
        }
    };

    if (N <= 1000 && Q <= 1000) {
        sub1();
    }

    return 0;
}

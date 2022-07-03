#include <bits/stdc++.h>

using i64 = long long;

template<typename T>
struct FenwickTree2D {
    const int n, m;
    std::map<int, std::vector<int>> info;
    FenwickTree2D(int n, int m) : n(n), m(m) {
        for (int i = 0; i < n; ++i) {
            info[i].resize(m + 1);
        }
    }
    void add(int x, int y, T v) {
        for (int j = y + 1; j <= m; j += j & -j) {
            info[x - 1][j - 1] += v;
        }
    }
    T sum(int x, int y) {
        T ans = 0;
        for (int j = y; j > 0; j -= j & -j) {
            ans += info[x - 1][j - 1];
        }
        return ans;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    FenwickTree2D<int> fw(1000000, N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        fw.add(A[i], i, 1);
    }
    while (Q--) {

    }


    return 0;
}

#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct FenwickTree {
    const int n;
    std::vector<T> info;
    FenwickTree(int n) : n(n), info(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            info[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += info[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int N, Q, X[200005], L, R, V, P, O;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        std::cin >> X[i];
    }
    FenwickTree<i64> fw(N);
    for (int i = 0; i < Q; ++i) {
        std::cin >> O;
        if (O == 1) {
            std::cin >> L >> R >> V;
            --L;
            fw.add(L, V);
            fw.add(R, -V);
        } else {
            std::cin >> P;
            --P;
            std::cout << X[P] + fw.sum(P + 1) << "\n";
        }
    }
    
    return 0;
}
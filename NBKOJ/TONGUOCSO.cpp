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


int N, T, A[1000005], lf[10000005], L, R;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::memset(lf, 0x3f, sizeof(lf));
    for (int i = 2; i * i <= 10000000; ++i) {
        for (int j = i * i; j <= 10000000; j += i) {
            lf[j] = std::min(lf[j], i);
        }
    }
    for (int i = 2; i <= 10000000; ++i) {
        if (lf[i] == lf[0]) {
            lf[i] = i;
        }
    }
    std::cin >> N >> T;
    FenwickTree<i64> fw(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        fw.add(i, lf[A[i]] + 1);
    }
    while (T--) {
        std::cin >> L >> R;
        std::cout << fw.rangeSum(L - 1, R) << "\n";
    }
    
    return 0;
}
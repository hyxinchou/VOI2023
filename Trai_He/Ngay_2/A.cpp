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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::pair<int, int>> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i].first;
        A[i].second = i;
    }
    std::sort(A.begin(), A.end());
    std::vector<std::array<int, 4>> queries;
    for (int i = 0; i < Q; ++i) {
        int I, J, K;
        std::cin >> I >> J >> K;
        --I, --J;
        queries.push_back({K, I, J, i});
    }
    std::sort(queries.begin(), queries.end());
    FenwickTree<int> fw(N);
    int l = 0;
    for (int i = 0; i < N; ++i) {
        fw.add(i, 1);
    }
    std::vector<int> ans(Q);
    for (auto [K, I, J, ID] : queries) {
        while (l < N && A[l].first <= K) {
            fw.add(A[l].second, -1);
            ++l;
        }
        ans[ID] = fw.rangeSum(I, J + 1);
    }
    for (int i = 0; i < Q; ++i) {
        std::cout << ans[i] << "\n";
    }

    return 0;
}

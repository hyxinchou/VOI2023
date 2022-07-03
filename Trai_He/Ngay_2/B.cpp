#include <bits/stdc++.h>

using i64 = long long;

template<typename T>
struct SegmentTree {
    const int n;
    std::vector<std::multiset<T>> info;
    SegmentTree(int n) : n(n), info(4 << std::__lg(n)) {}
    SegmentTree(std::vector<T> init) : SegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p].insert(init[l]);
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            for (auto v : info[2 * p]) {
                info[p].insert(v);
            }
            for (auto v : info[2 * p + 1]) {
                info[p].insert(v);
            }
        };
        build(1, 0, n);
    }
    void modify(int p, int l, int r, int pos, T x, T v) {
        info[p].erase(info[p].find(x));
        info[p].insert(v);
        if (r - l == 1) {
            return;
        }
        int m = (l + r) / 2;
        if (pos < m) {
            modify(2 * p, l, m, pos, x, v);
        } else {
            modify(2 * p + 1, m, r, pos, x, v);
        }
    }
    void modify(int pos, T x, T v) {
        modify(1, 0, n, pos, x, v);
    }
    T rangeQueryMin(int p, int l, int r, int x, int y, T v) {
        if (l >= y || r <= x) {
            return std::numeric_limits<T>::max();
        }
        if (x <= l && r <= y) {
            auto itr = info[p].lower_bound(v);
            if (itr == info[p].end()) {
                return std::numeric_limits<T>::max();
            }
            return *itr;
        }
        int m = (l + r) / 2;
        return std::min(rangeQueryMin(2 * p, l, m, x, y, v), rangeQueryMin(2 * p + 1, m, r, x, y, v));
    }
    T rangeQueryMin(int x, int y, T v) {
        return rangeQueryMin(1, 0, n, x, y, v);
    }
    T rangeQueryMax(int p, int l, int r, int x, int y, T v) {
        if (l >= y || r <= x) {
            return -std::numeric_limits<T>::max();
        }
        if (x <= l && r <= y) {
            auto itr = info[p].upper_bound(v);
            if (itr == info[p].begin()) {
                return -std::numeric_limits<T>::max();
            }
            --itr;
            return *itr;
        }
        int m = (l + r) / 2;
        return std::max(rangeQueryMax(2 * p, l, m, x, y, v), rangeQueryMax(2 * p + 1, m, r, x, y, v));
    }
    T rangeQueryMax(int x, int y, T v) {
        return rangeQueryMax(1, 0, n, x, y, v);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    SegmentTree<int> sg(A);
    for (int i = 0; i < Q; ++i) {
        int O;
        std::cin >> O;
        if (O == 1) {
            int X, V;
            std::cin >> X >> V;
            --X;
            sg.modify(X, A[X], V);
            A[X] = V;
        } else if (O == 2) {
            int X, Y, V;
            std::cin >> X >> Y >> V;
            --X, --Y;
            int ans = sg.rangeQueryMin(X, Y + 1, V);
            if (ans == std::numeric_limits<i64>::max()) {
                std::cout << "-1\n";
            } else {
                std::cout << ans << "\n";
            }
        } else if (O == 3) {
            int X, Y, V;
            std::cin >> X >> Y >> V;
            --X, --Y;
            int ans = sg.rangeQueryMax(X, Y + 1, V);
            if (ans == -std::numeric_limits<i64>::max()) {
                std::cout << "-1\n";
            } else {
                std::cout << ans << "\n";
            }
        }
    }

    return 0;
}

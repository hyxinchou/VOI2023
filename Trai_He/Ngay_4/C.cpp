#include <bits/stdc++.h>

using i64 = long long;

template<typename T>
struct SegmentTree {
    const int n;
    std::vector<T> info, lazy;
    SegmentTree(int n) : n(n), info(4 << std::__lg(n)) {}
    void pull_or(int p) {
        info[p] = info[2 * p] | info[2 * p + 1];
    }
    void pull_and(int p) {
        info[p] = info[2 * p] & info[2 * p + 1];
    }
    void add_xor(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return;
        }
        if (x <= l && r <= y) {

        }
    }
    void add(int x, T v) {
        add(1, 0, n, x, v);
    }
    T get(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return std::numeric_limits<T>::max();
        }
        if (x <= l && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return std::min(get(2 * p, l, m, x, y), get(2 * p + 1, m, r, x, y));
    }
    T get(int x, int y) {
        return get(1, 0, n, x, y);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    std::cin >> S;
    int Q;
    std::cin >> Q;

    auto sub1 = [&]() -> void {
        while (Q--) {
            int l, r;
            std::cin >> l >> r;
            char c, d;
            std::cin >> c >> d;
            for (int j = l; j <= r; ++j) {
                if (S[j] == c) {
                    S[j] = d;
                }
            }
        }
        std::cout << S << "\n";
    };

    auto sub4 = [&]() -> void {

    };

    if (int(S.size()) <= 2000 && Q <= 2000) {
        sub1();
    }

    return 0;
}

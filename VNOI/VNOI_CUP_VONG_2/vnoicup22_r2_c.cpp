#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) {
        std::iota(f.begin(), f.end(), 0);
    }
    int leader(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
    int size(int x) {
        return siz[leader(x)];
    }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    auto sub = [&]() -> void {
        DSU d(N);
        DSU d2(N);
        std::map<int, std::map<int, bool>> f;
        for (int i = 0; i < Q; ++i) {
            int O;
            std::cin >> O;
            if (O == 1) {
                int U, V;
                std::cin >> U >> V;
                --U, --V;
                d.merge(U, V);
                if (f[U][V]) {
                    d2.merge(U, V);
                }
            } else if (O == 2) {
                int U, V;
                std::cin >> U >> V;
                --U, --V;
                f[U][V] = f[V][U] = true;
                if (d.same(U, V)) {
                    d2.merge(U, V);
                }
            } else {
                int K;
                std::cin >> K;
                --K;
                std::cout << d2.size(K) - 1 << "\n";
            }
        }
    };

    sub();

    return 0;
}

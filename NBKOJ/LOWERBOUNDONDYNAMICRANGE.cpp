#include <bits/stdc++.h>

using i64 = long long;

template<typename T>
struct SegmentTree {
	const int n;
	std::vector<T> info;
	SegmentTree(int n) : n(n), info(4 << std::__lg(n)) {}
	void pull(int p) {
		info[p] = std::max(info[2 * p], info[2 * p + 1]);
	}
	void modify(int p, int l, int r, int x, T v) {
		if (r - l == 1) {
			info[p] = v;
		} else {
			int m = (l + r) / 2;
			if (x < m) {
				modify(2 * p, l, m, x, v);
			} else {
				modify(2 * p + 1, m, r, x, v);
			}
			pull(p);
		}
	}
	void modify(int x, T v) {
		modify(1, 0, n, x, v);
	}
	T rangeMax(int p, int l, int r, int x, int y) {
		if (l >= y || r <= x) {
			return -std::numeric_limits<int>::max();
		}
		if (x <= l && r <= y) {
			return info[p];
		}
		int m = (l + r) / 2;
		return std::max(rangeMax(2 * p, l, m, x, y), rangeMax(2 * p + 1, m, r, x, y));
	}
	T rangeMax(int x, int y) {
		return rangeMax(1, 0, n, x, y);
	}
};

int N, Q, X[200005], P, V, O;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> Q;
    SegmentTree<int> sg(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> X[i];
        sg.modify(i, X[i]);
    }
    while (Q--) {
        std::cin >> O;
        if (O == 1) {
            std::cin >> P >> V;
            --P;
            sg.modify(P, V);
        } else {
            std::cin >> V;
            int l = -1, r = N;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (sg.rangeMax(0, m + 1) >= V) {
                    r = m;
                } else {
                    l = m;
                }
            }
            if (sg.rangeMax(0, r + 1) >= V) {
                std::cout << r + 1 << "\n";
            } else {
                std::cout << "-1\n";
            }
        }
    }
    
    return 0;
}
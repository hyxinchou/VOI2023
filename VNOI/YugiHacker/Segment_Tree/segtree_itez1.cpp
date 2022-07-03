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
	void add(int p, int l, int r, int x, T v) {
		if (r - l == 1) {
			info[p] = v;
		} else {
			int m = (l + r) / 2;
			if (x < m) {
				add(2 * p, l, m, x, v);
			} else {
				add(2 * p + 1, m, r, x, v);
			}
			pull(p);
		}
	}
	void add(int x, T v) {
		add(1, 0, n, x, v);
	}
	T get(int p, int l, int r, int x, int y) {
		if (l >= y || r <= x) {
			return -std::numeric_limits<T>::max();
		}
		if (x <= l && r <= y) {
			return info[p];
		}
		int m = (l + r) / 2;
		return std::max(get(2 * p, l, m, x, y), get(2 * p + 1, m, r, x, y));
	}
	T get(int x, int y) {
		return get(1, 0, n, x, y);
	}
};

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    SegmentTree<int> sg(N);
    for (int i = 0; i < N; ++i) {
        int v; cin >> v;
        sg.add(i, v);
    }
    int Q; cin >> Q;
    while (Q--) {
        int O; cin >> O;
        if (O == 1) {
            int X, Y; cin >> X >> Y;
            sg.add(X - 1, Y);
        } else {
            int L, R; cin >> L >> R;
            cout << sg.get(L - 1, R) << "\n";
        }
    }

    return 0;
}

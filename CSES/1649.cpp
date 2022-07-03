#include <bits/stdc++.h>

template<typename T>
struct SegmentTree {
	const int n;
	std::vector<T> info;
	SegmentTree(int n) : n(n), info(4 << std::__lg(n)) {}
	void pull(int p) {
		info[p] = std::min(info[2 * p], info[2 * p + 1]);
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
	T rangeMin(int p, int l, int r, int x, int y) {
		if (l >= y || r <= x) {
			return std::numeric_limits<int>::max();
		}
		if (x <= l && r <= y) {
			return info[p];
		}
		int m = (l + r) / 2;
		return std::min(rangeMin(2 * p, l, m, x, y), rangeMin(2 * p + 1, m, r, x, y));
	}
	T rangeMin(int x, int y) {
		return rangeMin(1, 0, n, x, y);
	}
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, Q; cin >> N >> Q;

	SegmentTree<int> sg(N);

	for (int i = 0; i < N; ++i) {
		int X; cin >> X;
		sg.modify(i, X);
	}

	while (Q--) {
		int O, A, B; cin >> O >> A >> B;
		if (O == 1) {
			sg.modify(A - 1, B);
		} else {
			cout << sg.rangeMin(A - 1, B) << "\n";
		}
	}
	
	return 0;
}
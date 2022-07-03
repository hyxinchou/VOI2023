#include <bits/stdc++.h>

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
			return 0;
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

	int N, M; cin >> N >> M;

	SegmentTree<int> sg(N);

	for (int i = 0; i < N; ++i) {
		int H; cin >> H;
		sg.add(i, H);
	}

	for (int i = 0; i < M; ++i) {
		int R; cin >> R;
		int l = 0, r = N;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (sg.get(0, m) >= R) {
				r = m;
			} else {
				l = m;
			}
		}
		if (sg.get(0, r) >= R) {
			cout << r << " ";
			sg.add(r - 1, sg.get(0, r) - R);
		} else {
			cout << "0 ";
		}
	}
	
	return 0;
}
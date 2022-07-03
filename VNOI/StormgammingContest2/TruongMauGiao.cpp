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
	vector<multiset<int>> info(200005);
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
		info[B[i]].insert(A[i]);
	}
	SegmentTree<long long> sg(200005);
	for (int i = 0; i <= 200000; ++i) {
		if (info[i].empty()) {
			sg.modify(i, 1E18);
		} else {
			sg.modify(i, *--info[i].end());
		}
	}
	while (Q--) {
		int C, D; cin >> C >> D;
		--C;
		info[B[C]].erase(info[B[C]].find(A[C]));
		info[D].insert(A[C]);
		if (info[B[C]].empty()) {
			sg.modify(B[C], 1E18);
		} else {
			sg.modify(B[C], *--info[B[C]].end());
		}
		sg.modify(D, *--info[D].end());
		B[C] = D;
		cout << sg.rangeMin(0, 200001) << "\n";
	}
	
	return 0;
}
#include <bits/stdc++.h>

using int64 = long long;

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
			return 0;
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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	vector<int> H(N);
	for (auto &v : H) {
		cin >> v;
	}
	vector<int> A(N);
	for (auto &v : A) {
		cin >> v;
	}
	SegmentTree<int64> sg(N + 1);
	int64 ans = 0;
	for (int i = 0; i < N; ++i) {
		int64 v = sg.rangeMax(0, H[i]);
		// cout << v << " " << A[i] << " " << H[i] << "\n";
		ans = max(ans, v + A[i]);
		sg.modify(H[i], v + A[i]);
	}
	cout << ans << "\n";
	
	return 0;
}
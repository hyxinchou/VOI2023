#include <bits/stdc++.h>

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

	vector<int> A;
	int v; while (cin >> v) {
		A.push_back(v);
	}
	reverse(A.begin(), A.end());
	int N = int(A.size());
	SegmentTree<int> sg(100005);
	vector<int> dp(N, 0);
	dp[0] = 1;
	sg.modify(A[0], 1);
	for (int i = 1; i < N; ++i) {
		dp[i] = sg.rangeMax(0, A[i] + 1) + 1;
		sg.modify(A[i], dp[i]);
	}
	cout << *max_element(dp.begin(), dp.end()) << "\n";
	dp.clear();
	reverse(A.begin(), A.end());
	for (int i = 0; i < N; ++i) {
		int l = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
		if (l >= 0 && l < int(dp.size())) {
			dp[l] = A[i];
		} else {
			dp.push_back(A[i]);
		}
	}
	cout << int(dp.size()) << "\n";
	
	return 0;
}
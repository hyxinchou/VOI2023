#include <bits/stdc++.h>

template<typename T>
struct FenwickTree2D {
	const int n, m;
	std::vector<std::vector<T>> info;
	FenwickTree2D(int n, int m) : n(n), m(m), info(n, std::vector<T> (m)) {}
	void add(int x, int y, T v) {
		for (int i = x + 1; i <= n; i += i & -i) {
			for (int j = y + 1; j <= m; j += j & -j) {
				info[i - 1][j - 1] += v;
			}
		}
	}
	T sum(int x, int y) {
		T ans = 0;
		for (int i = x; i > 0; i -= i & -i) {
			for (int j = y; j > 0; j -= j & -j) {
				ans += info[i - 1][j - 1];
			}
		}
		return ans;
	}
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, Q; cin >> N >> Q;

	FenwickTree2D<int> fw(N, N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char C; cin >> C;
			fw.add(i, j, C == '*' ? 1 : 0);
		}
	}

	while (Q--) {
		int X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2;
		cout << fw.sum(X2, Y2) - fw.sum(X2, Y1 - 1) - fw.sum(X1 - 1, Y2) + fw.sum(X1 - 1, Y1 - 1) << "\n";
	}
	
	return 0;
}
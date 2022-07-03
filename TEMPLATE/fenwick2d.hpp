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
template<typename T>
struct SegmentTreeLazy {
	const int n;
	std::vector<T> info, lazy;
	SegmentTreeLazy(int n) : n(n), info(4 << std::__lg(n)), lazy(4 << std::__lg(n)) {}
	void pull(int p) {
		info[p] = std::min(info[2 * p], info[2 * p + 1]);
	}
	void pull_lazy(int p, int l, int r) {
		if (lazy[p]) {
			info[p] += lazy[p];
			if (2 * p + 1 < int(info.size())) {
				lazy[2 * p] += lazy[p];
				lazy[2 * p + 1] += lazy[p];
			}
			lazy[p] = 0;
		}
	}
	void add(int p, int l, int r, int x, int y, T v) {
		pull_lazy(p, l, r);
		if (l >= y || r <= x) {
			return;
		}
		if (x <= l && r <= y) {
			lazy[p] += v;
			pull_lazy(p, l, r);
			return;
		}
		int m = (l + r) / 2;
		add(2 * p, l, m, x, y, v);
		add(2 * p + 1, m, r, x, y, v);
		pull(p);
	}
	void add(int x, int y, T v) {
		add(1, 0, n, x, y, v);
	}
	T get(int p, int l, int r, int x, int y) {
		pull_lazy(p, l, r);
		if (l >= y || r <= x) {
			return std::numeric_limits<T>::max();
		}
		if (x <= l && r <= y) {
			return info[p];
		}
		int m = (l + r) / 2;
		return std::min(get(2 * p, l, m, x, y), get(2 * p + 1, m, r, x, y));
	}
	T get(int x, int y) {
		return get(1, 0, n, x, y);
	}
};

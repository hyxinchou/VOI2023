int LOG = 20;
struct LCA {
	const int n;
	std::vector<int> d;
	std::vector<std::vector<int>> up, E;
	LCA(int n) : n(n) {
		d = std::vector<int> (n, 0);
		E = std::vector<std::vector<int>> (n);
		up = std::vector<std::vector<int>> (n, std::vector<int> (LOG, 0));
	}
	void add_edges(int u, int v) {
		E[u].push_back(v);
		E[v].push_back(u);
	}
	void dfs_lca(int u, int p) {
		for (auto v : E[u]) {
			if (v != p) {
				d[v] = d[u] + 1;
				up[v][0] = u;
				for (int i = 1; i < LOG; ++i) {
					up[v][i] = up[up[v][i - 1]][i - 1];
				}
				dfs_lca(v, u);
			}
		}
	}
	int lca(int u, int v) {
		if (d[u] < d[v]) {
			std::swap(u, v);
		}
		int diff = d[u] - d[v];
		for (int i = LOG - 1; ~i; --i) {
			if (diff >> i & 1) {
				u = up[u][i];
			}
		}
		if (u == v) {
			return u;
		}
		for (int i = LOG - 1; ~i; --i) {
			if (up[u][i] != up[v][i]) {
				u = up[u][i];
				v = up[v][i];
			}
		}
		return up[u][0];
	}
	int k_th(int u, int k) {
		if (d[u] < k) {
			return -1;
		}
		for (int i = LOG - 1; ~i; --i) {
			if (k >> i & 1) {
				u = up[u][i];
			}
		}
		return u;
	}
};
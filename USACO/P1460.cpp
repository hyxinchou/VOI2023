#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int V; cin >> V;

	vector<int> nd(V);
	for (auto &v : nd) {
		cin >> v;
	}

	int G; cin >> G;

	vector<vector<int>> io(G, vector<int> (V));
	for (auto &v : io) {
		for (auto &vv : v) {
			cin >> vv;
		}
	}

	vector<int> ans;

	for (int mask = 0; mask < (1 << G); ++mask) {
		vector<int> hv(V, 0);
		for (int i = 0; i < G; ++i) {
			if (mask >> i & 1) {
				for (int j = 0; j < V; ++j) {
					hv[j] += io[i][j];
				}
			}
		}
		bool flag = true;
		for (int i = 0; i < V; ++i) {
			flag = hv[i] < nd[i] ? false : flag;
		}
		if (flag) {
			// cout << mask << "\n";
			vector<int> res;
			for (int i = 0; i < G; ++i) {
				if (mask >> i & 1) {
					res.push_back(i);
				}
			}
			if (ans.empty()) {
				ans = res;
			} else if (ans.size() > res.size()) {
				ans = res;
			} else if (ans.size() == res.size()) {
				bool sl = false;
				for (int i = 0; i < int(ans.size()); ++i) {
					if (ans[i] == res[i]) {
						continue;
					} else {
						sl = ans[i] > res[i] ? true : false;
						break;
					}
				}
				if (sl) {
					ans = res;
				}
			}
		}
	}

	cout << ans.size() << " ";
	for (auto v : ans) {
		cout << v + 1 << " \n"[v == ans.back()];
	}
	
	return 0;
}
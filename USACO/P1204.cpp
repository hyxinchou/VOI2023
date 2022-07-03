#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;

	vector<pair<int, int>> io(N);
	for (auto &[u, v] : io) {
		cin >> u >> v;
	}

	sort(io.begin(), io.end());

	int mn = io[0].first;
	int mx = io[0].second;

	int ans = 0, ans2 = 1E9;

	for (auto [u, v] : io) {
		if (u <= mx) {
			mx = max(mx, v);
		} else {
			ans2 = min(ans2, u - mx);
			ans = max(ans, mx - mn);
			mn = u;
			mx = v;
		}
	}

	ans = max(ans, mx - mn);
	if (ans2 == 1E9) {
		ans2 = 0;
	}

	cout << ans << " " << ans2 << "\n";
	
	return 0;
}
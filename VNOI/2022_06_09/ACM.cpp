#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	vector<pair<int, int>> A(N);
	for (auto &[u, v] : A) {
		cin >> u >> v;
	}
	vector<vector<int>> dp(N, vector<int> (2, 0x3f3f3f3f));
	dp[0][0] = 0;
	dp[0][1] = 0;
	for (int i = 0; i < N; ++i) {
		dp[i + 1][0] = min(dp[i][0] + A[i].first, dp[i][1] + A[i].second);
		dp[i + 1][1] = min(dp[])
	}
	
	return 0;
}
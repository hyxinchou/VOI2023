#include <bits/stdc++.h>

using i64 = long long;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	freopen("knight.in", "r", stdin);
	freopen("knight.out", "w", stdout);

	int N, M; cin >> N >> M;
	vector<vector<i64>> dp(N, vector<i64> (M, 0));
	dp[0][0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (i && j >= 2) {
				dp[i][j] += dp[i - 1][j - 2];
			}
			if (j && i >= 2) {
				dp[i][j] += dp[i - 2][j - 1];
			}
		}
	}
	cout << dp[N - 1][M - 1] << "\n";
	
	return 0;
}
#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	freopen("king2.in", "r", stdin);
	freopen("king2.out", "w", stdout);

	vector<vector<int>> A(8, vector<int> (8));
	for (auto &a : A) {
		for (auto &aa : a) {
			cin >> aa;
		}
	}
	constexpr int inf = int(1e9 + 7);
	vector<vector<int>> dp(8, vector<int> (8, inf));
	dp[7][0] = A[7][0];
	for (int i = 7; ~i; --i) {
		for (int j = 0; j < 8; ++j) {
			if (i) {
				dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] + A[i - 1][j]);
			}
			if (j + 1 < 8) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + A[i][j + 1]);
			}
			if (i && j + 1 < 8) {
				dp[i - 1][j + 1] = min(dp[i - 1][j + 1], dp[i][j] + A[i - 1][j + 1]);
			}
		}
	}
	cout << dp[0][7] << "\n";
	
	return 0;
}
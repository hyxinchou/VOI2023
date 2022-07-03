#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	vector<vector<int>> A(N);
	for (int i = 0; i < N; ++i) {
		A[i].resize(i + 1);
		for (auto &a : A[i]) {
			cin >> a;
		}
	}
	constexpr int inf = int(1e9 + 7);
	vector<vector<int>> dp(N, vector<int> (N, -inf));
	dp[0][0] = A[0][0];
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + A[i][j]);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + A[i][j + 1]);
		}
	}
	int ans = -inf;
	for (int i = 0; i < N; ++i) {
		ans = max(ans, dp[N - 1][i]);
	}
	cout << ans << "\n";
	
	return 0;
}
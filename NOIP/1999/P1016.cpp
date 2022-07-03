#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	double D1, C, D2, P; cin >> D1 >> C >> D2 >> P;
	int N; cin >> N;
	vector<pair<double, double>> A(N);
	for (auto &[u, v] : A) {
		cin >> u >> v;
	}
	constexpr double inf = 1E9;
	vector<vector<double>> dp(N + 1, vector<double> (2, inf));
	dp[0][0] = D1 * P;
	dp[0][1] = C * P;
	for (int i = 0; i < N; ++i) {
		dp[i + 1][0] = min(dp[i][0] + D1 * A[])
	}
	
	return 0;
}
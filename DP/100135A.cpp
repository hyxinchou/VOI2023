#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	freopen("ladder.in", "r", stdin);
	freopen("ladder.out", "w", stdout);

	int N; cin >> N;
	vector<int> A(N);
	for (auto &a : A) {
		cin >> a;
	}
	if (N == 1) {
		cout << A[0] << "\n";
		return 0;
	}
	constexpr int inf = int(1e6 + 7);
	vector<int> dp(N, -inf);
	dp[0] = A[0];
	dp[1] = max(A[0] + A[1], A[1]);
	for (int i = 2; i < N; ++i) {
		dp[i] = max({dp[i], dp[i - 1] + A[i], dp[i - 2] + A[i]});
	}
	cout << dp[N - 1] << "\n";
	
	return 0;
}
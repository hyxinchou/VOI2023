#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	freopen("lepus.in", "r", stdin);
	freopen("lepus.out", "w", stdout);

	int N; cin >> N;
	string S; cin >> S;
	vector<int> dp(N, -1);
	dp[0] = 0;
	for (int i = 1; i < N; ++i) {
		if (S[i] != 'w') {
			if (dp[i - 1] != -1) {
				dp[i] = max(dp[i], dp[i - 1] + (S[i] == '"' ? 1 : 0));
			}
			if (i - 3 >= 0 && dp[i - 3] != -1) {
				dp[i] = max(dp[i], dp[i - 3] + (S[i] == '"' ? 1 : 0));
			}
			if (i - 5 >= 0 && dp[i - 5] != -1) {
				dp[i] = max(dp[i], dp[i - 5] + (S[i] == '"' ? 1 : 0));
			}
		}
	}
	cout << dp[N - 1] << "\n";
	
	return 0;
}
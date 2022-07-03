#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	vector<long long> A(N);
	for (auto &a : A) {
		cin >> a;
	}
	vector<long long> dp;
	for (int i = 0; i < N; ++i) {
		int l = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
		if (l >= 0 && l < int(dp.size())) {
			dp[l] = A[i];
		} else {
			dp.push_back(A[i]);
		}
	}
	cout << int(dp.size()) << "\n";
	
	return 0;
}
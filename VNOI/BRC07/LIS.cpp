#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	vector<int> A(N);
	for (auto &v : A) {
		cin >> v;
	}
	sort(A.begin(), A.end());
	int add = 1;
	long long ans = 0;
	for (int i = 1; i < N; ++i) {
		ans += 1LL * add;
		if (A[i] > A[i - 1]) {
			++add;
		}
	}
	ans += 1LL * add;
	cout << ans << "\n";
	
	return 0;
}
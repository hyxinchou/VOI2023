#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	vector<int> A(1000005, 0);
	for (int i = 0; i < N; ++i) {
		int v; cin >> v;
		++A[v];
	}
	int ans = 1;
	for (int i = 2; i <= 1000000; ++i) {
		int cnt = 0;
		for (int j = i; j <= 1000000; j += i) {
			cnt += A[j];
		}
		ans = cnt >= 2 ? max(ans, i) : ans;
	}
	cout << ans << "\n";
	
	return 0;
}
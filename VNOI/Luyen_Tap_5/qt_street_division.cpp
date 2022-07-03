#include <bits/stdc++.h>

using i64 = long long;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, K; cin >> N >> K;
	vector<int> P(N);
	for (auto &p : P) {
		cin >> p;
	}
	i64 r = accumulate(P.begin(), P.end(), 0LL);
	i64 l = *max_element(P.begin(), P.end()) - 1;
	while (r - l > 1) {
		i64 m = (l + r) / 2;
		int cnt = 0;
		i64 sum = 0;
		for (int i = 0; i < N; ++i) {
			if (sum + 1LL * P[i] <= m) {
				sum += P[i];
			} else {
				sum = P[i];
				++cnt;
			}
		}
		if (cnt < K) {
			r = m;
		} else {
			l = m;
		}
	}
	cout << r << "\n";
	
	return 0;
}
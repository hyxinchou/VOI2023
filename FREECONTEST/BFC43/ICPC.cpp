#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, L; cin >> N >> L;

	vector<int64_t> A(N);
	for (auto &a : A) {
		cin >> a;
	}

	int64_t cnt = 0, pent = 0, Time = 0;
	
	sort(A.begin(), A.end());

	for (int i = 0; i < N; ++i) {
		if (L >= A[i]) {
			L -= A[i];
			pent += Time + A[i];
			Time += A[i];
			++cnt;
		} else {
			break;
		}
	}

	cout << cnt << " " << pent << "\n";

	return 0;
}
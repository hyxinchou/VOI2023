#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, Q; cin >> N >> Q;

	vector<int> X(N);
	for (auto &x : X) {
		cin >> x;
	}

	vector<long long> prefix_sum = {0};
	for (auto x : X) {
		prefix_sum.push_back(prefix_sum.back() + 1LL * x);
	}

	while (Q--) {
		int A, B; cin >> A >> B;
		cout << prefix_sum[B] - prefix_sum[A - 1] << "\n";
	}
	
	return 0;
}
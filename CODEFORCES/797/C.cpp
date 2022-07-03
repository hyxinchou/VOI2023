#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> S(N);
		for (auto &v : S) {
			cin >> v;
		}
		vector<int> F(N);
		for (auto &v : F) {
			cin >> v;
		}
		int nw = 0;
		for (int i = 0; i < N; ++i) {
			cout << F[i] - max(nw, S[i]) << " \n"[i == N - 1];
			nw = F[i];
		}
	}	
	
	return 0;
}
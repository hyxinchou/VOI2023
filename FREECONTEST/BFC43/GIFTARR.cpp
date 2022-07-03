#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;

	while (T--) {
		int N, X; cin >> N >> X;

		vector<int> S(N);
		for (auto &s : S) {
			cin >> s;
		}

		if (*min_element(S.begin(), S.end()) <= X && X <= *max_element(S.begin(), S.end())) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
	return 0;
}
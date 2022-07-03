#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;

	string S; cin >> S;

	int step = (N - 11) / 2;

	if (count(S.begin(), S.end(), '8') <= step) {
		cout << "NO\n";
	} else {
		for (int i = 0; i < N; ++i) {
			if (step && S[i] == '8') {
				--step;
			} else if (!step && S[i] == '8') {
				if (i <= (N - 11)) {
					cout << "YES\n";
				} else {
					cout << "NO\n";
				}
				break;
			}
		}
	}
	
	return 0;
}
#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--)	{
		int N; cin >> N;
		vector<pair<int, int>> A(N);
		vector<vector<int>> F(10005);
		set<int> Unq;
		for (auto &[h, w] : A) {
			cin >> h >> w;
			F[h].push_back(w);
			Unq.insert(h);
		}
		for (auto v : Unq) {
			sort(F[v].begin(), F[v].end());
		}

	}
	
	return 0;
}
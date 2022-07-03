#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<vector<int>> A(N, vector<int> (N, 0));
	for (int i = 0; i < M; ++i) {
		int U, V; cin >> U >> V;
		--U, --V;
		A[U][V] = 1;
		A[V][U] = 1;
	}
	for (auto v : A) {
		for (auto vv : v) {
			cout << vv << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
#include <bits/stdc++.h>

bool hv[1005][1005];

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<int> E(N, 0);
	for (int i = 0; i < M; ++i) {
		int U, V; cin >> U >> V;
		--U, --V;
		if (!hv[U][V]) {
			++E[U];
			++E[V];
		}
		hv[U][V] = true;
		hv[V][U] = true;
	}
	for (int i = 0; i < N; ++i) {
		cout << E[i] << " \n"[i == N - 1];
	}
	
	return 0;
}
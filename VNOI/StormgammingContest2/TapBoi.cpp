#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M, K; cin >> N >> M >> K;
	int X, Y, U, V; cin >> X >> Y >> U >> V;
	--X, --Y, --U, --V;
	vector<string> A(N);
	for (auto &a : A) {
		cin >> a;
	}
	--K;
	queue<pair<int, int>> que;
	vector<vector<int>> d(N, vector<int> (M, -1));
	auto DD = [&](int x, int y, int f) -> void {
		for (int i = 0; i <= min(K, N - x - 1); ++i) {
			if (d[x + i][y] != -1 || A[x + i][y] == '@') {
				break;
			}
			que.push(make_pair(x + i, y));
			d[x + i][y] = f;
		}
	};
	auto UU = [&](int x, int y, int f) -> void {
		for (int i = 0; i <= min(K, x); ++i) {
			if (d[x - i][y] != -1 || A[x - i][y] == '@') {
				break;
			}
			que.push(make_pair(x - i, y));
			d[x - i][y] = f;
		}
	};
	auto LL = [&](int x, int y, int f) -> void {
		for (int i = 0; i <= min(K, y); ++i) {
			if (d[x][y - i] != -1 || A[x][y - i] == '@') {
				break;
			}
			que.push(make_pair(x, y - i));
			d[x][y - i] = f;
		}
	};
	auto RR = [&](int x, int y, int f) -> void {
		for (int i = 0; i <= min(K, M - y - 1); ++i) {
			if (d[x][y + i] != -1 || A[x][y + i] == '@') {
				break;
			}
			que.push(make_pair(x, y + i));
			d[x][y + i] = f;
		}
	};
	int ans = 1E9;
	que.push(make_pair(X, Y));
	d[X][Y] = 0;
	while (que.size()) {
		auto [uu, vv] = que.front();
		// cout << uu << " " << vv << "";
		que.pop();
		// cout << "::";
		if (vv + 1 < M && A[uu][vv + 1] != '@' && d[uu][vv + 1] == -1) {
			// cout << uu << " " << vv + 1 << " :: ";
			RR(uu, vv + 1, d[uu][vv] + 1);
		}
		if (vv - 1 >= 0 && A[uu][vv - 1] != '@' && d[uu][vv - 1] == -1) {
			// cout << uu + 1 << " " << vv - 1;
			LL(uu, vv - 1, d[uu][vv] + 1);
		}
		if (uu + 1 < N && A[uu + 1][vv] != '@' && d[uu + 1][vv] == -1) {
			// cout << uu + 1 << " " << vv << " :: ";
			DD(uu + 1, vv, d[uu][vv] + 1);
		}
		if (uu - 1 >= 0 && A[uu - 1][vv] != '@' && d[uu - 1][vv] == -1) {
			// cout << uu - 1 << " " << vv << " :: ";
			UU(uu - 1, vv, d[uu][vv] + 1);
		}
		if (d[U][V] != -1) {
			ans = min(ans, d[U][V]);
		}
	}
	for (int i = 0; i < N; ++i) {
		fill(d[i].begin(), d[i].end(), -1);
	}
	que.push(make_pair(X, Y));
	d[X][Y] = 0;
	while (que.size()) {
		auto [uu, vv] = que.front();
		// cout << uu << " " << vv << "";
		que.pop();
		// cout << "::";
		if (uu + 1 < N && A[uu + 1][vv] != '@' && d[uu + 1][vv] == -1) {
			// cout << uu + 1 << " " << vv << " :: ";
			DD(uu + 1, vv, d[uu][vv] + 1);
		}
		if (uu - 1 >= 0 && A[uu - 1][vv] != '@' && d[uu - 1][vv] == -1) {
			// cout << uu - 1 << " " << vv << " :: ";
			UU(uu - 1, vv, d[uu][vv] + 1);
		}
		if (vv + 1 < M && A[uu][vv + 1] != '@' && d[uu][vv + 1] == -1) {
			// cout << uu << " " << vv + 1 << " :: ";
			RR(uu, vv + 1, d[uu][vv] + 1);
		}
		if (vv - 1 >= 0 && A[uu][vv - 1] != '@' && d[uu][vv - 1] == -1) {
			// cout << uu + 1 << " " << vv - 1;
			LL(uu, vv - 1, d[uu][vv] + 1);
		}
		if (d[U][V] != -1) {
			ans = min(ans, d[U][V]);
		}
	}
	for (int i = 0; i < N; ++i) {
		fill(d[i].begin(), d[i].end(), -1);
	}
	que.push(make_pair(X, Y));
	d[X][Y] = 0;
	while (que.size()) {
		auto [uu, vv] = que.front();
		// cout << uu << " " << vv << "";
		que.pop();
		// cout << "::";
		if (uu - 1 >= 0 && A[uu - 1][vv] != '@' && d[uu - 1][vv] == -1) {
			// cout << uu - 1 << " " << vv << " :: ";
			UU(uu - 1, vv, d[uu][vv] + 1);
		}
		if (uu + 1 < N && A[uu + 1][vv] != '@' && d[uu + 1][vv] == -1) {
			// cout << uu + 1 << " " << vv << " :: ";
			DD(uu + 1, vv, d[uu][vv] + 1);
		}
		if (vv + 1 < M && A[uu][vv + 1] != '@' && d[uu][vv + 1] == -1) {
			// cout << uu << " " << vv + 1 << " :: ";
			RR(uu, vv + 1, d[uu][vv] + 1);
		}
		if (vv - 1 >= 0 && A[uu][vv - 1] != '@' && d[uu][vv - 1] == -1) {
			// cout << uu + 1 << " " << vv - 1;
			LL(uu, vv - 1, d[uu][vv] + 1);
		}
		if (d[U][V] != -1) {
			ans = min(ans, d[U][V]);
		}
	}
	if (ans == 1E9) {
		ans = -1;
	}
	cout << ans << "\n";
	
	return 0;
}
#include <bits/stdc++.h>

int st[1000005][30], lg[1000005];
int H[1000005], J[1000005], Next[1000005];

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	lg[1] = 0;
	for (int i = 2; i <= 1000000; ++i) {
		lg[i] = lg[i / 2] + 1;
	}
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
		st[i][0] = H[i];
	}
	for (int j = 1; j <= 20; j++) {
    	for (int i = 0; i + (1 << j) <= N; i++) {
        	st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    	}
    }
    auto get = [&](int L, int R) -> int {
    	--R;
    	int j = lg[R - L + 1];
		int maximum = max(st[L][j], st[R - (1 << j) + 1][j]);
		return maximum;
    };
	for(int i = 0; i < N; ++i) {
		cin >> J[i];
	}
	memset(Next, -1, sizeof(Next));
	for (int i = 0; i < N; ++i) {
		int l = i, r = N + 1;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (get(i, m) > H[i]) {
				r = m;	
			} else {
				l = m;
			}
		}
		if (r > 0 && r <= N && get(i, r) > H[i] && r != i + 1) {
			Next[i] = r - 1;
		}
	}
	memset(st, -1, sizeof(st));
	for (int i = 0; i < N; ++i) {
		st[i][0] = Next[i];
	}
	for (int j = 1; j <= 20; ++j) {
		for (int i = 0; i < N; ++i) {
			if (st[i][j - 1] == -1) {
				break;
			}
			st[i][j] = st[st[i][j - 1]][j - 1];
		}
	}
	for (int i = 0; i < N; ++i) {
		int v = i;
		for (int j = 0; j <= 20; ++j) {
			if (J[i] >> j & 1) {
				v = st[v][j];
				if (v == -1) {
					break;
				}
			}
		}
		if (v == -1) {
			cout << v << " ";
		} else {
			cout << H[v] << " ";
		}
	}

	return 0;
}

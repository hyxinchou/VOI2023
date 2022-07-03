#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	int C = 0;
	int nw = 0;
	int i;
	for (i = 1; ; ++i) {
		if (nw + i > N) {
			break;
		}
		C ^= 1;
		nw += i;
	}
	--i;
	if (!C) {
		if (nw == N) {
			cout << i << "/" << 1 << "\n";
		} else {
			int x = i + 1;
			int y = 1;
			++nw;
			cout << x - (N - nw) << "/" << y + (N - nw) << "\n";
		}
	} else {
		if (nw == N) {
			cout << 1 << "/" << i << "\n";
		} else {
			int x = 1;
			int y = i + 1;
			++nw;
			cout << x + (N - nw) << "/" << y - (N - nw) << "\n";
		}
	}
	
	return 0;
}
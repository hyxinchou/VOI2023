#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	for (int i = 100; ; ++i) {
		if (i * 3 < 1000) {
			bool z = false;
			set<int> Unq;
			int C = i;
			while (C) {
				Unq.insert(C % 10);
				z = C % 10 ? z : true;
				C /= 10;
			}
			C = i * 2;
			while (C) {
				Unq.insert(C % 10);
				z = C % 10 ? z : true;
				C /= 10;
			}
			C = i * 3;
			while (C) {
				Unq.insert(C % 10);
				z = C % 10 ? z : true;
				C /= 10;
			}
			if (!z && int(Unq.size()) == 9) {
				cout << i << " " << 2 * i << " " << 3 * i << "\n";
			}
		} else {
			break;
		}
	}	
	
	return 0;
}
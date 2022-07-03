#include <bits/stdc++.h>

template<typename T>
struct FenwickTree2D {
	const int n, m;
	std::vector<std::vector<T>> info;
	FenwickTree2D(int n, int m) : n(n), m(m), info(n, std::vector<T> (m)) {}
	void add(int x, int y, T v) {
		for (int i = x + 1; i <= n; i += i & -i) {
			info[i - 1][y] += v;
		}
	}
	T sum(int x, int y) {
		T ans = 0;
		for (int i = x; i > 0; i -= i & -i) {
			ans += info[i - 1][y];
		}
		return ans;
	}
	T rangeSum(int l, int r) {
		T ans = 0;
		for (int i = 0; i < 26; ++i) {
			ans += sum(r, i) - sum(l, i) > 0 ? 1 : 0;
			// if (sum(r, i) - sum(l, i) > 0) {
			// 	std::cout << i << " ";
			// }
		}
		// std::cout << "\n";
		return ans;
	}
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	string S; cin >> S;
	FenwickTree2D<int> fw(N, 26);
	for (int i = 0; i < N; ++i) {
		fw.add(i, int(S[i] - 'a'), 1);
	}
	int Q; cin >> Q;
	while (Q--) {
		int O; cin >> O;
		if (O == 1) {
			int I; cin >> I;
			char C; cin >> C;
			fw.add(I - 1, int(S[I - 1] - 'a'), -1);
			fw.add(I - 1, int(C - 'a'), 1);
			S[I - 1] = C;
		} else {
			int L, R; cin >> L >> R;
			cout << fw.rangeSum(L - 1, R) << "\n";
		}
	}
	
	return 0;
}
#include <bits/stdc++.h>

template <typename T>
struct FenwickTree {
    const int n;
    std::vector<T> info;
    FenwickTree(int n) : n(n), info(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            info[i - 1] ^= v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans ^= info[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) ^ sum(l);
    }
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, Q; cin >> N >> Q;

	FenwickTree<int> fw(N);

	for (int i = 0; i < N; ++i) {
		int X; cin >> X;
		fw.add(i, X);
	}

	while (Q--) {
		int A, B; cin >> A >> B;
		cout << fw.rangeSum(A - 1, B) << "\n";
	}
	
	return 0;
}
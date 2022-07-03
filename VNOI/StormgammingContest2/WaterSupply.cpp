#include <bits/stdc++.h>

template <typename T>
struct FenwickTree {
    const int n;
    std::vector<T> info;
    FenwickTree(int n) : n(n), info(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            info[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += info[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, W; cin >> N >> W;
	FenwickTree<long long> fw(200005);
	for (int i = 0; i < N; ++i) {
		int S, T, P; cin >> S >> T >> P;
		fw.add(S, P);
		fw.add(T, -P);
	}
	bool ok = true;
	for (int i = 0; i <= 200000; ++i) {
		ok = fw.sum(i + 1) > W ? false : ok;
	}
	cout << (ok ? "Yes" : "No") << "\n";
	
	return 0;
}
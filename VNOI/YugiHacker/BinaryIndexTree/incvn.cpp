#include <bits/stdc++.h>

constexpr int MOD = 5000000;
using int64 = long long;

template <typename T>
struct FenwickTree {
    const int n;
    std::vector<T> info;
    FenwickTree(int n) : n(n), info(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            info[i - 1] += v;
            info[i - 1] %= MOD;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += info[i - 1];
            ans %= MOD;
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    void clear() {
    	std::fill(info.begin(), info.end(), 0);
    }
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, K; cin >> N >> K;
	vector<int> A(N);
	for (auto &v : A) {
		cin >> v;
	}
	vector<vector<int64>> dp(N, vector<int64> (K, 0));
	for (int i = 0; i < N; ++i) {
		dp[i][0] = 1;
	}
	FenwickTree<int64> fw(100005);
	for (int i = 1; i < K; ++i) {
		for (int j = 0; j < N; ++j) {
			dp[j][i] = fw.sum(A[j]);
			fw.add(A[j], dp[j][i - 1]);
		}
		fw.clear();
	}
	int64 ans = 0;
	for (int i = 0; i < N; ++i) {
		// cout << dp[i][K - 1] << " ";
		ans += dp[i][K - 1];
		ans %= MOD;
	}
	cout << ans << "\n";
	
	return 0;
}
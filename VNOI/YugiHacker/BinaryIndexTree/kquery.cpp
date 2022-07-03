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

	int N; cin >> N;
	vector<pair<int, int>> A(N);
	int cnt = 0;
	for (auto &[a, i] : A) {
		cin >> a;
		i = cnt++;
	}
	int Q; cin >> Q;
	vector<array<int, 4>> query(Q);
	cnt = 0;
	for (auto &[i, j, k, f] : query) {
		cin >> i >> j >> k;
		--i, --j;
		f = cnt++;
	}
	sort(query.begin(), query.end(), [&](const auto &x, const auto &y) {
		return x[2] < y[2];
	});
	sort(A.begin(), A.end());
	FenwickTree<int> fw(N);
	int ll = upper_bound(A.begin(), A.end(), make_pair(query[0][2], -1)) - A.begin();
	for (int i = ll; i < N; ++i) {
		fw.add(A[i].second, 1);
	}
	vector<int> ans(Q);
	for (int i = 0; i < Q; ++i) {
		auto [l, r, k, f] = query[i];
		while (ll < N && A[ll].first <= k) {
			fw.add(A[ll].second, -1);
			++ll;
		}
		ans[f] = fw.rangeSum(l, r + 1);
	}
	for (int i = 0; i < Q; ++i) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}
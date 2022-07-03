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

	int N, Q; cin >> N >> Q;

	vector<int> all;
	vector<int> P(N);
	for (auto &p : P) {
		cin >> p;
		all.push_back(p);
	}

	vector<tuple<char, int, int>> query(Q);
	for (auto &[O, A, B] : query) {
		cin >> O >> A >> B;
		all.push_back(A);
		all.push_back(B);
	}

	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());

	int f = 0;
	map<int, int> zip;

	for (auto v : all) {
		zip[v] = f++;
	}

	vector<int> cnt(f, 0);
	for (auto p : P) {
		++cnt[zip[p]];
	}

	FenwickTree<int> fw(f);
	for (int i = 0; i < f; ++i) {
		fw.add(i, cnt[i]);
	}

	for (auto [O, A, B] : query) {
		if (O == '!') {
			fw.add(zip[P[A - 1]], -1);
			fw.add(zip[B], 1);
			P[A - 1] = B;
		} else {
			cout << fw.rangeSum(zip[A], zip[B] + 1) << "\n";
		}
	}
	
	return 0;
}
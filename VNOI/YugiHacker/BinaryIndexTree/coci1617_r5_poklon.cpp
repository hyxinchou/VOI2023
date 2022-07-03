#include <bits/stdc++.h>

int A[500005];
int Ans;
int C[500005];

int block_size;
struct Query {
	int l, r, idx;
	bool operator<(Query other) const {
		return std::make_pair(l / block_size, r) < std::make_pair(other.l / block_size, other.r);
	}
};

void add(int idx) {
	++C[A[idx]];
	if (C[A[idx]] == 2) {
		++Ans;
	} else if (C[A[idx]] == 3) {
		--Ans;
	}
}
 
void remove(int idx) {
	--C[A[idx]];
	if (C[A[idx]] == 2) {
		++Ans;
	} else if (C[A[idx]] == 1) {
		--Ans;
	}
}
 
int get() {
	return Ans;
}
 
std::vector<int> mo_s_algorithm(std::vector<Query> queries) {
	int queries_size = int(queries.size());
	std::vector<int> answer(queries_size, 0);
	std::sort(queries.begin(), queries.end(), [&](const auto &lhs, const auto &rhs) {
		if (lhs.l / block_size != rhs.l / block_size) {
			return lhs.l < rhs.l;
		}
		return (lhs.l / block_size & 1) ? (lhs.r < rhs.r) : (lhs.r > rhs.r);
	});
	int cur_l = 0, cur_r = -1;
	for (auto [l, r, idx] : queries) {
		while (cur_l > l) {
			--cur_l;
			add(cur_l);
		}
		while (cur_r < r) {
			++cur_r;
			add(cur_r);
		}
		while (cur_l < l) {
			remove(cur_l);
			++cur_l;
		}
		while (cur_r > r) {
			remove(cur_r);
			--cur_r;
		}
		answer[idx] = get();
	}
	return answer;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	block_size = int(sqrt(N + .0) + 1);
	vector<int> all;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		all.push_back(A[i]);
	}
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	map<int, int> mp;
	for (int i = 0; i < int(all.size()); ++i) {
		mp[all[i]] = i;
	}
	for (int i = 0; i < N; ++i) {
		A[i] = mp[A[i]];
	}
	// for (int i = 0; i < N; ++i) {
	// 	cout << A[i] << " \n"[i == N - 1];
	// }
	vector<Query> queries;
	for (int i = 0; i < Q; ++i) {
		int l, r; cin >> l >> r;
		--l, --r;
		queries.push_back({l, r, i});
	}
	auto ans = mo_s_algorithm(queries);
	for (int i = 0; i < Q; ++i) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}
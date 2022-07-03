#include <bits/stdc++.h>

using i64 = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<std::pair<i64, i64>, null_type, std::less<std::pair<i64, i64>>, rb_tree_tag, tree_order_statistics_node_update>

template<typename T>
struct RMQ {
	const int n;
	std::vector<std::vector<T>> info;
	RMQ(const std::vector<T> &init) : n(int(init.size())) {
		int lg = std::__lg(n);
		info.assign(n, std::vector<T> (lg + 1));
		for (int i = 0; i <= lg; ++i) {
			for (int j = 0; j + (1 << i) <= n; ++j) {
				info[j][i] = (!i ? init[j] : std::min(info[j][i - 1], info[j + (1 << (i - 1))][i - 1]));
			}
		}
	}
	T get(int l, int r) {
		int k = std::__lg(r - l);
		return std::min(info[l][k], info[r - (1 << k)][k]);
	}
};

template <class Fun>
struct y_combinator {
    Fun fun_;
    template <class... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_((*this), std::forward<Args>(args)...);
    }
};
template <class Fun> y_combinator<std::decay_t<Fun>> make_y_combinator(Fun&& fun_) {
    return { std::forward<Fun>(fun_) };
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

	i64 N, K;
	std::cin >> N >> K;
	std::vector<i64> A(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
	}
	RMQ<i64> rmq(A);

	auto calc = make_y_combinator([&](auto && f, int l, int r) -> i64 {
		if (l == r) {
			return 3 * A[l] <= K;
		}
		int m = (l + r) / 2;
		i64 ans = 0;
		ordered_set os;
		for (int i = m + 1, j = m; i <= r; ++i) {
			while (j >= l && rmq.get(j, m + 1) >= rmq.get(m + 1, i + 1)) {
				os.insert(std::make_pair(A[j], j));
				--j;
			}
			ans += os.order_of_key(std::make_pair(K - rmq.get(m + 1, i + 1) - A[i], i64(1e9)));
		}
		os.clear();
		for (int i = m, j = m + 1; i >= l; --i) {
			while (j <= r && rmq.get(i, m + 1) < rmq.get(m + 1, j + 1)) {
				os.insert(std::make_pair(A[j], j));
				++j;
			}
			ans += os.order_of_key(std::make_pair(K - rmq.get(i, m + 1) - A[i], i64(1e9)));
		}
		return ans + f(l, m) + f(m + 1, r);
	});

	std::cout << calc(0, N - 1) << "\n";

    return 0;
}

#include <bits/stdc++.h>

using i64 = long long;

template<typename T>
struct SegmentTree {
    const int n;
    std::vector<T> info;
    SegmentTree(int n) : n(n), info(4 << std::__lg(n)) {}
    void pull(int p) {
        info[p] = std::min(info[2 * p], info[2 * p + 1]);
    }
    void add(int p, int l, int r, int x, T v) {
        if (r - l == 1) {
            info[p] = v;
        } else {
            int m = (l + r) / 2;
            if (x < m) {
                add(2 * p, l, m, x, v);
            } else {
                add(2 * p + 1, m, r, x, v);
            }
            pull(p);
        }
    }
    void add(int x, T v) {
        add(1, 0, n, x, v);
    }
    T get(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return std::numeric_limits<T>::max();
        }
        if (x <= l && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return std::min(get(2 * p, l, m, x, y), get(2 * p + 1, m, r, x, y));
    }
    T get(int x, int y) {
        return get(1, 0, n, x, y);
    }
};

int N, K, E[100005];
i64 dp[100005], answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    SegmentTree<i64> sg(N);
    std::memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < N; ++i) {
        std::cin >> E[i];
        if (i <= K) {
            dp[i] = E[i];
            sg.add(i, E[i]);
        }
    }
    if (K == N) {
        answer = *std::min_element(E, E + N);
    } else {
        dp[K + 1] = E[K + 1] + sg.get(0, K + 1);
        sg.add(K + 1, dp[K + 1]);
        for (int i = K + 2; i < N; ++i) {
            dp[i] = E[i] + sg.get(i - K - 1, i);
            sg.add(i, dp[i]);
        }
        answer = i64(1e18);
        for (int i = N - 1; i >= N - 1 - K; --i) {
            answer = std::min(answer, dp[i]);
        }
    }
    std::cout << std::accumulate(E, E + N, 0LL) - answer << "\n";

    return 0;
}

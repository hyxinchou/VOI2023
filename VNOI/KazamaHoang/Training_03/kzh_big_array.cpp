#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> B(N);
    for (int i = 0; i < N; ++i) {
        int K;
        std::cin >> K;
        for (int j = 0; j < K; ++j) {
            int V;
            std::cin >> V;
            B[i].push_back(V);
        }
    }
    std::vector<int> A(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> A[i];
        --A[i];
    }
    i64 ans = -i64(1e18);
    i64 ans2 = -i64(1e18);
    std::vector<i64> max_in_segment(N, 0);
    std::vector<i64> max_prefix(N, 0);
    std::vector<i64> min_prefix(N, 0);
    std::vector<i64> max_element(N);
    std::vector<i64> total_element(N, 0);
    for (int i = 0; i < N; ++i) {
        i64 r = 0;
        i64 f = 0;
        i64 sum = 0;
        i64 max = 0;
        i64 min = 0;
        for (int j = 0; j < int(B[i].size()); ++j) {
            r = std::max(i64(0), r + i64(B[i][j]));
            f = std::max(r, f);
            sum += B[i][j];
            max = std::max(max, sum);
            min = std::min(min, sum);
        }
        max_prefix[i] = max;
        min_prefix[i] = min;
        max_element[i] = *std::max_element(B[i].begin(), B[i].end());
        total_element[i] = std::accumulate(B[i].begin(), B[i].end(), i64(0));
        max_in_segment[i] = f;
    }
    i64 Min = 0, Sum = 0;
    for (int i = 0; i < M; ++i) {
        ans = std::max(ans, max_in_segment[A[i]]);
        ans = std::max(ans, Sum + max_prefix[A[i]] - Min);
        Min = std::min(Min, Sum + min_prefix[A[i]]);
        ans = std::max(ans, Sum + total_element[A[i]] - Min);
        ans2 = std::max(ans2, max_element[A[i]]);
        Sum += total_element[A[i]];
    }
    if (ans2 < 0) {
        ans = ans2;
    }
    std::cout << ans << "\n";

    return 0;
}

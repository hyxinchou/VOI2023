#include <bits/stdc++.h>

using i64 = long long;

bool visited[105];
int K, R, M, N, S[105], answer;
std::pair<int, int> A[25], B[105];
std::bitset<105> can[25];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> K >> R >> M;
    for (int i = 0; i < M; ++i) {
        std::cin >> A[i].first >> A[i].second;
    }
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i].first >> B[i].second >> S[i];
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int a = A[i].first - B[j].first;
            int b = A[i].second - B[j].second;
            if (a * a + b * b <= R * R) {
                can[i][j] = 1;
            }
        }
    }
    answer = 0;
    for (int mask = 0; mask < (1 << M); ++mask) {
        if (__builtin_popcount(mask) > K) {
            continue;
        }
        memset(visited, false, sizeof(visited));
        std::bitset<105> r;
        for (int i = 0; i < M; ++i) {
            if (mask >> i & 1) {
                r |= can[i];
            }
        }
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (r[i]) {
                sum += S[i];
            }
        }
        answer = std::max(answer, sum);
    }
    std::cout << answer << "\n";

    return 0;
}

#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = int(1e9) + 7;

int N, A[100005];
i64 Prefix[100005], sum, sum2, answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    sum = 0;
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        sum += A[i];
    }
    for (int i = 0; i < N; ++i) {
        sum -= A[i];
        Prefix[i] = sum * A[i];
        Prefix[i] %= MOD;
        sum2 += Prefix[i];
        sum2 %= MOD;
    }
    for (int i = 0; i < N; ++i) {
        sum2 -= Prefix[i];
        sum2 %= MOD;
        sum2 += MOD;
        sum2 %= MOD;
        answer += sum2 * A[i];
        answer %= MOD;
    }
    std::cout << answer << "\n";

    return 0;
}

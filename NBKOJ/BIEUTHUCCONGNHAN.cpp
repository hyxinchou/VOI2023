#include <bits/stdc++.h>

using i64 = long long;

int N, A[1005];
i64 sum, answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    sum = 0;
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        sum += A[i];
    }
    answer = -int(1e9);
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            if (j - i == 1) {
                answer = std::max(answer, sum - A[i] - A[i + 1] - A[j + 1] + 1LL * A[i] * A[i + 1] * A[j + 1]);
            } else {
                answer = std::max(answer, sum - A[i] - A[i + 1] - A[j] - A[j + 1] + 1LL * A[i] * A[i + 1] + 1LL * A[j] * A[j + 1]);
            }
        }
    }
    std::cout << answer << "\n";
        
    return 0;
}
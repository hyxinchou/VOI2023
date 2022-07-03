#include <bits/stdc++.h>

using i64 = long long;

int N, B[100005], C[100005], answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }
    for (int j = 0; j < N; ++j) {
        std::cin >> C[j];
    }
    std::sort(B, B + N);
    std::sort(C, C + N);
    answer = int(2e9);
    for (int i = 0; i < N; ++i) {
        if (B[i] <= 0) {
            int l = std::lower_bound(C, C + N, -B[i]) - C;
            if (l < N) {
                answer = std::min(answer, std::abs(B[i] + C[l]));
            }
            if (l) {
                --l;
                answer = std::min(answer, std::abs(B[i] + C[l]));
            }
        } else {
            int l = std::lower_bound(C, C + N, -B[i]) - C;
            if (l < N) {
                answer = std::min(answer, std::abs(B[i] + C[l]));
            }
            if (l) {
                --l;
                answer = std::min(answer, std::abs(B[i] + C[l]));
            }
        }
    }
    std::cout << answer << "\n";
    
    return 0;
}
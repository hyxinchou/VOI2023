#include <bits/stdc++.h>

using i64 = long long;

int S1, S2, S3, C[100], max, answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> S1 >> S2 >> S3;
    for (int i = 1; i <= S1; ++i) {
        for (int j = 1; j <= S2; ++j) {
            for (int k = 1; k <= S3; ++k) {
                ++C[i + j + k];
            }
        }
    }
    max = 0;
    for (int i = 3; i <= S1 + S2 + S3; ++i) {
        if (C[i] > max) {
            max = C[i];
            answer = i;
        }
    }
    std::cout << answer << "\n";

    return 0;
}

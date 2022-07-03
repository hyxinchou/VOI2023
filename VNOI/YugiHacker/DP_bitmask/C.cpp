#include <bits/stdc++.h>

using i64 = long long;

i64 A[8][10005], dp[10005][300], Sum[10005][300], answer;
int N;
std::vector<int> mask;
bool negative;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    negative = true;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> A[i][j];
            negative = (A[i][j] >= 0 ? false : negative);
        }
    }
    for (int i = 0; i < (1 << 8); ++i) {
        bool can = true;
        for (int j = 0; j < 7; ++j) {
            if (i >> j & 1 && i >> (j + 1) & 1) {
                can = false;
            }
        }
        if (can) {
            mask.push_back(i);
        }
    }
    answer = -i64(1e18);
    memset(Sum, 0, sizeof(Sum));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < int(mask.size()); ++j) {
            i64 sum = 0;
            for (int k = 0; k < 8; ++k) {
                if (mask[j] >> k & 1) {
                    sum += A[k][i];
                }
            }
            Sum[i][mask[j]] = sum;
            if (mask[j]) {
                answer = std::max(answer, sum);
            }
        }
    }
    memset(dp, -0x3f, sizeof(dp));
    for (int i = 0; i < int(mask.size()); ++i) {
        dp[0][mask[i]] = Sum[0][mask[i]];
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < int(mask.size()); ++j) {
            for (int k = 0; k < int(mask.size()); ++k) {
                if (!(mask[j] & mask[k])) {
                    dp[i][mask[k]] = std::max(dp[i][mask[k]], dp[i - 1][mask[j]] + Sum[i][mask[k]]);
                }
            }
        }
    }
    if (!negative) {
        for (int i = 0; i < int(mask.size()); ++i) {
            answer = std::max(answer, dp[N - 1][mask[i]]);
        }
    }
    std::cout << answer << "\n";


    return 0;
}

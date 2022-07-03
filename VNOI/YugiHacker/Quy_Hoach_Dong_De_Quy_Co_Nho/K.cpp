#include <bits/stdc++.h>

using i64 = long long;

std::string S, T, answer;
int dp[3005][3005], len;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> S >> T;
    int n = int(S.size());
    int n2 = int(T.size());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n2; ++j) {
            if (S[i] == T[j]) {
                dp[i + 1][j + 1] = std::max(dp[i][j], dp[i][j] + 1);
                len = std::max(len, dp[i + 1][j + 1]);
            } else {
                dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
                len = std::max(len, dp[i + 1][j + 1]);
            }
        }
    }
    answer = "";
    int i = 0, j = 0;
    for (; i < n; ++i) {
        for (j = 0; j < n2; ++j) {
            if (dp[i + 1][j + 1] == len) {
                break;
            }
        }
        if (dp[i + 1][j + 1] == len) {
            break;
        }
    }
    ++i, ++j;
    for (int ii = n - 1; ii >= 0; --ii) {
        for (int jj = n2 - 1; jj >= 0; --jj) {
            if (dp[ii + 1][jj + 1] == len && S[ii] == T[jj] && ii < i && jj < j) {
                answer += S[ii];
                --len;
                i = ii;
                j = jj;
            }
        }
    }
    std::reverse(answer.begin(), answer.end());
    std::cout << answer << "\n";

    return 0;
}

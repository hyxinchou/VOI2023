#include <bits/stdc++.h>

using i64 = long long;

i64 dp2[100000];
int N, S, A[1005], answer;
bool dp[100000];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    std::memset(dp, false, sizeof(dp));
    std::memset(dp2, 0, sizeof(dp2));
    dp[0] = true;
    dp2[0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = S; j >= 0; --j) {
            if (j >= A[i]) {
                if (dp[j - A[i]]) {
                    if (!dp[j]) {
                        dp[j] = true;
                        dp2[j] = dp2[j - A[i]];
                    } else {
                        dp2[j] += dp2[j - A[i]];
                    }
                }
            }
        }
    }
    for (int i = S; i >= 0; --i) {
        if (dp[i]) {
            answer = i;
            break;
        }
    }
    std::cout << answer << "\n";
    if (answer) {
        std::cout << dp2[answer] << "\n";
    }
    
    return 0;
}
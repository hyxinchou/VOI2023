#include <bits/stdc++.h>

using i64 = long long;

int N, Block[105], dp[105][1 << 3][1 << 3][1 << 3], answer, ways, dp2[105][1 << 3][1 << 3][1 << 3];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> Block[i];
        --Block[i];
    }
    std::memset(dp, -1, sizeof(dp));
    std::memset(dp2, 0, sizeof(dp2));
    std::function<bool(int, int, int)> ok = [&](int a, int b, int c) {
        bool r = true;
        if (a >> 0 & 1 && (b >> 2 & 1 || c >> 1 & 1)) {
            r = false;
        }
        if (a >> 1 & 1 && (c >> 0 & 1 || c >> 2 & 1)) {
            r = false;
        }
        if (a >> 2 & 1 && (b >> 0 & 1 || c >> 1 & 1)) {
            r = false;
        }
        if (b >> 0 & 1 && (a >> 2 & 1 || c >> 2 & 1)) {
            r = false;
        }
        if (b >> 2 & 1 && (a >> 0 & 1 || c >> 0 & 1)) {
            r = false;
        }
        if (c >> 0 & 1 && (b >> 2 & 1 || a >> 1 & 1)) {
            r = false;
        }
        if (c >> 1 & 1 && (a >> 0 & 1 || a >> 2 & 1)) {
            r = false;
        }
        if (c >> 2 & 1 && (b >> 0 & 1 || a >> 1 & 1)) {
            r = false;
        }
        return r;
    };
    if (N <= 2) {
        answer = 0;
        if (N == 1) {
            for (int mask = 0; mask < (1 << 3); ++mask) {
                if (Block[0] != -1 && mask >> Block[0] & 1) {
                    continue;
                }
                if (answer < __builtin_popcount(mask)) {
                    answer = std::max(answer, __builtin_popcount(mask));
                    ways = 1;
                } else if (answer == __builtin_popcount(mask)) {
                    ++ways;
                }
            }
            std::cout << answer << " " << ways << "\n";
        } else if (N == 2) {
            for (int mask = 0; mask < (1 << 3); ++mask) {
                for (int mask2 = 0; mask2 < (1 << 3); ++mask2) {
                    if (Block[0] != -1 && mask >> Block[0] & 1) {
                        continue;
                    }
                    if (Block[1] != -1 && mask2 >> Block[1] & 1) {
                        continue;
                    }
                    if (ok(mask, mask2, 0)) {
                        if (answer < __builtin_popcount(mask) + __builtin_popcount(mask2)) {
                            answer = __builtin_popcount(mask) + __builtin_popcount(mask2);
                            ways = 1;
                        } else if (answer == __builtin_popcount(mask) + __builtin_popcount(mask2)) {
                            ++ways;
                        }
                    }
                }
            }
            std::cout << answer << " " << ways << "\n";
        }
        return 0;
    }
    for (int mask = 0; mask < (1 << 3); ++mask) {
        for (int mask2 = 0; mask2 < (1 << 3); ++mask2) {
            for (int mask3 = 0; mask3 < (1 << 3); ++mask3) {
                if (Block[0] != -1 && mask >> Block[0] & 1) {
                    continue;
                }
                if (Block[1] != -1 && mask2 >> Block[1] & 1) {
                    continue;
                }
                if (Block[2] != -1 && mask3 >> Block[2] & 1) {
                    continue;
                }
                if (ok(mask, mask2, mask3)) {
                    int a = __builtin_popcount(mask);
                    int b = __builtin_popcount(mask2);
                    int c = __builtin_popcount(mask3);
                    if (dp[2][mask][mask2][mask3] < a + b + c) {
                        dp[2][mask][mask2][mask3] = a + b + c;
                        dp2[2][mask][mask2][mask3] = 1;
                    } else if (dp[2][mask][mask2][mask3] == a + b + c) {
                        ++dp2[2][mask][mask2][mask3];
                    }
                }
            }
        }
    }
    for (int i = 3; i < N; ++i) {
        for (int mask = 0; mask < (1 << 3); ++mask) {
            for (int mask2 = 0; mask2 < (1 << 3); ++mask2) {
                for (int mask3 = 0; mask3 < (1 << 3); ++mask3) {
                    for (int mask4 = 0; mask4 < (1 << 3); ++mask4) {
                        if (Block[i - 3] != -1 && mask >> Block[i - 3] & 1) {
                            continue;
                        }
                        if (Block[i - 2] != -1 && mask2 >> Block[i - 2] & 1) {
                            continue;
                        }
                        if (Block[i - 1] != -1 && mask3 >> Block[i - 1] & 1) {
                            continue;
                        }
                        if (Block[i] != -1 && mask4 >> Block[i] & 1) {
                            continue;
                        }
                        if (dp[i - 1][mask][mask2][mask3] && ok(mask2, mask3, mask4)) {
                            int a = __builtin_popcount(mask4);
                            if (dp[i][mask2][mask3][mask4] < dp[i - 1][mask][mask2][mask3] + a) {
                                dp[i][mask2][mask3][mask4] = dp[i - 1][mask][mask2][mask3] + a;
                                dp2[i][mask2][mask3][mask4] = dp2[i - 1][mask][mask2][mask3];
                            } else if (dp[i][mask2][mask3][mask4] == dp[i - 1][mask][mask2][mask3] + a) {
                                dp2[i][mask2][mask3][mask4] += dp2[i - 1][mask][mask2][mask3];
                            }
                        }
                    }
                }
            }
        }
    }
    for (int mask = 0; mask < (1 << 3); ++mask) {
        for (int mask2 = 0; mask2 < (1 << 3); ++mask2) {
            for (int mask3 = 0; mask3 < (1 << 3); ++mask3) {
                if (answer < dp[N - 1][mask][mask2][mask3]) {
                    answer = dp[N - 1][mask][mask2][mask3];
                }
            }
        }
    }
    for (int mask = 0; mask < (1 << 3); ++mask) {
        for (int mask2 = 0; mask2 < (1 << 3); ++mask2) {
            for (int mask3 = 0; mask3 < (1 << 3); ++mask3) {
                if (answer == dp[N - 1][mask][mask2][mask3]) {
                    ways += dp2[N - 1][mask][mask2][mask3];
                }
            }
        }
    }
    std::cout << answer << " " << ways << "\n";

    return 0;
}

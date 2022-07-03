#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        A[i] %= 3;
    }
    std::vector<int> Prefix = {0};
    std::vector<int> Prefix2 = {0};
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += A[i];
        sum %= 3;
        Prefix.push_back(sum);
    }
    sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += A[i] * Prefix[i + 1];
        sum %= 3;
        Prefix2.push_back(sum);
    }
    std::vector<std::vector<int>> cnt(3, std::vector<int> (3, 0));
    cnt[0][0] = 1;
    i64 ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int f = 0; f < 3; ++f) {
            for (int f2 = 0; f2 < 3; ++f2) {
                int r = (((Prefix[i] * (Prefix[i - 1] - f) - (Prefix2[i - 1] - f2)) % 3) + 3) % 3;
                if (!r) {
                    ans += 1LL * cnt[f][f2];
                }
            }
        }
        ++cnt[Prefix[i]][Prefix2[i]];
    }
    std::cout << ans << "\n";

    return 0;
}

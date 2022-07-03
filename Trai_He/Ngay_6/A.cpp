#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // freopen("ff.inp", "r", stdin);
    // freopen("ff.out", "w", stdout);

    int N, K;
    std::cin >> N >> K;
    int ans = N / K;
    int P = N % K;
    int G = N - P;
    ++ans;
    int add = std::min(G, K - P);
    N -= add;
    int ans2 = N / K;
    while (ans2 * K < N) {
        ++ans2;
    }
    std::cout << ans + ans2 << "\n";

    return 0;
}

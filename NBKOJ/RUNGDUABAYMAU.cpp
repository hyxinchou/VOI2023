#include <bits/stdc++.h>

using i64 = long long;

int N, M, C[100005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        std::cin >> C[i];
    }
    int l = 0, r = N + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        bool ok = true;
        i64 sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += 1LL * C[i];
        }
        if (sum < M) {
            ok = false;
        }
        for (int i = m; i < N; ++i) {
            sum -= C[i - m];
            sum += C[i];
            if (sum < M) {
                ok = false;
            }
        }
        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }
    std::cout << r << "\n";
    
    return 0;
}
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, C;
    std::cin >> N >> C;
    std::vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> P[i];
    }
    if (~C & 1) {
        i64 ans = 0;
        std::sort(P.begin(), P.end());
        for (auto v : P) {
            std::cerr << v << " ";
        }
        std::cerr << "\n";
        std::set<int> Unq;
        for (auto v : P) {
            Unq.insert(v);
        }
        std::vector<bool> vis(C, false);
        for (auto v : Unq) {
            if (vis[v]) {
                continue;
            }
            vis[v] = true;
            int op = (v + (C / 2)) % C;
            vis[op] = true;
            std::cerr << "[" << v << " " << op << "]\n";
            int l = std::lower_bound(P.begin(), P.end(), v) - P.begin();
            int r = std::upper_bound(P.begin(), P.end(), op) - P.begin();
            --r;
            std::cerr << "{" << l << " " << r << "} -> ";
            if (r < int(P.size()) && P[r] <= op) {
                if (r < l) {
                    std::swap(l, r);
                }
                int siz = r - l + 1;
                std::cerr << siz << "\n";
                ans -= 1LL * siz * (siz - 1) * (siz - 2) / 6;
            }
        }
        ans += 1LL * N * (N - 1) * (N - 2) / 6;
        std::cout << ans << "\n";
    }

    return 0;
}

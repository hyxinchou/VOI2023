#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int W, H, N;
    std::cin >> W >> H >> N;
    std::vector<std::pair<int, int>> Points(N);
    std::vector<int> all_x;
    for (auto &[x, y] : Points) {
        std::cin >> x >> y;
        all_x.push_back(x);
    }
    std::sort(all_x.begin(), all_x.end());
    all_x.erase(std::unique(all_x.begin(), all_x.end()), all_x.end());
    std::map<int, int> zip;
    for (int i = 0; i < int(all_x.size()); ++i) {
        zip[all_x[i]] = i;
    }
    std::vector<int> max(int(all_x.size()), -1);
    std::vector<int> min(int(all_x.size()), int(1e9));
    for (auto [x, y] : Points) {
        max[zip[x]] = std::max(max[zip[x]], y);
        min[zip[x]] = std::min(min[zip[x]], y);
    }
    std::vector<int> Prefix(int(all_x.size()), -1);
    int last = -1;
    for (auto v : all_x) {
        Prefix[zip[v]] = std::max(last, max[zip[v]]);
        last = std::max(last, Prefix[zip[v]]);
    }
    std::vector<int> Suffix(int(all_x.size()), -1);
    last = -1;
    for (int i = int(all_x.size()) - 1; i >= 0; --i) {
        Suffix[zip[all_x[i]]] = std::max(last, max[zip[all_x[i]]]);
        last = std::max(last, Suffix[zip[all_x[i]]]);
    }
    std::vector<int> Prefix2(int(all_x.size()), int(1e9));
    last = int(1e9);
    for (auto v : all_x) {
        Prefix2[zip[v]] = std::min(last, min[zip[v]]);
        last = std::min(last, Prefix2[zip[v]]);
    }
    std::vector<int> Suffix2(int(all_x.size()), int(1e9));
    last = int(1e9);
    for (int i = int(all_x.size()) - 1; i >= 0; --i) {
        Suffix2[zip[all_x[i]]] = std::min(last, min[zip[all_x[i]]]);
        last = std::min(last, Suffix2[zip[all_x[i]]]);
    }
    int l = 0, r = std::min(H, W) + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        bool ok = false;
        int lf = 0;
        while (lf < int(all_x.size()) && all_x[lf] - all_x[0] < m) {
            ++lf;
        }
        for (int v = 0; v < int(all_x.size()); ++v) {
            int lhs = -1;
            if (v - 1 >= 0) {
                lhs = std::max(lhs, Prefix[v - 1]);
            }
            while (lf < int(all_x.size()) && all_x[lf] - all_x[v] < m) {
                ++lf;
            }
            if (lf < int(all_x.size())) {
                lhs = std::max(lhs, Suffix[lf]);
            }
            int rhs = int(1e9);
            if (v - 1 >= 0) {
                rhs = std::min(rhs, Prefix2[v - 1]);
            }
            if (lf < int(all_x.size())) {
                rhs = std::min(rhs, Suffix2[lf]);
            }
            if (lhs - rhs + 1 <= m) {
                ok = true;
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

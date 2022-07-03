#include <bits/stdc++.h>

using i64 = long long;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int N, X, A[1005];
std::unordered_map<int, std::vector<std::pair<int, int>>, custom_hash> mp;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> X;
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            mp[A[i] + A[j]].push_back(std::make_pair(i, j));
        }
    }
    for (auto [x, y] : mp) {
        std::sort(mp[x].begin(), mp[x].end());
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (mp[X - A[i] - A[j]].size()) {
                int l = std::lower_bound(mp[X - A[i] - A[j]].begin(), mp[X - A[i] - A[j]].end(), std::make_pair(j + 1, -1)) - mp[X - A[i] - A[j]].begin();
                if (l < int(mp[X - A[i] - A[j]].size())) {
                    std::cout << i + 1 << " " << j + 1 << " " << mp[X - A[i] - A[j]][l].first + 1 << " " << mp[X - A[i] - A[j]][l].second + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    std::cout << "IMPOSSIBLE\n";
    
    return 0;
}
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

int T, X, lf[1000005], C[1000005], answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (int i = 2; i * i <= 1000000; ++i) {
        if (!lf[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                lf[j] = i;
            }
        }
    }
    for (int i = 2; i <= 1000000; ++i) {
        if (!lf[i]) {
            lf[i] = i;
        }
    }
    std::cin >> T;
    while (T--) {
        std::cin >> X;
        std::unordered_map<int, int, custom_hash> mp;
        while (X > 1) {
            ++mp[lf[X]];
            X /= lf[X];
        }
        answer = 1;
        for (auto [a, v] : mp) {
            answer *= (v + 1);
        }
        std::cout << answer << "\n";
    }
    
    return 0;
}
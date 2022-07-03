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

bool visited[1005];
int N, A[1005], d[1005], max, n;
std::vector<int> all, topo;
std::unordered_map<int, int, custom_hash> zip, C;
std::vector<std::vector<int>> E(1005);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        ++C[A[i]];
        all.push_back(A[i]);
    }
    std::sort(all.begin(), all.end());
    all.erase(std::unique(all.begin(), all.end()), all.end());
    n = int(all.size());
    for (int i = 0; i < n; ++i) {
        zip[all[i]] = i;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                --C[A[i]];
                --C[A[j]];
                if (C[A[j] - A[i]]) {
                    E[zip[A[i]]].push_back(zip[A[j]]);
                }
                ++C[A[i]];
                ++C[A[j]];
            }
        }
    }
    std::memset(visited, false, sizeof(visited));
    std::function<void(int)> dfs = [&](int root) {
        visited[root] = true;
        for (int v : E[root]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
        topo.push_back(root);
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    std::reverse(topo.begin(), topo.end());
    std::memset(d, 0, sizeof(d));
    for (int i = 0; i < n; ++i) {
        for (int v : E[topo[i]]) {
            d[v] = std::max(d[v], d[topo[i]] + 1);
        }
    }
    std::cout << *std::max_element(d, d + n) + 1 << "\n";
    
    return 0;
}
#include <bits/stdc++.h>

using i64 = long long;

int N, M, K, U, V, L, d[5005];
std::vector<std::vector<std::pair<int, int>>> E(5005);
i64 ways[5005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        std::cin >> K >> U >> V >> L;
        --U, --V;
        E[U].push_back(std::make_pair(L, V));
        if (K == 2) {
            E[V].push_back(std::make_pair(L, U));
        }
    }
    ways[0] = 1;
    std::memset(d, -1, sizeof(d));
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;
    pq.push({0, 0, 0});
    while (pq.size()) {
        int cost = pq.top()[0];
        int to = pq.top()[1];
        int parent = pq.top()[2];
        pq.pop();
        if (d[to] == -1) {
            d[to] = cost;
            ways[to] = ways[parent];
            for (int i = 0; i < int(E[to].size()); ++i) {
                if (d[E[to][i].second] == -1) {
                    pq.push({cost + E[to][i].first, E[to][i].second, to});
                }
            }
        } else if (d[to] == cost) {
            ways[to] += ways[parent];
        }
    }
    std::cout << d[N - 1] << " " << ways[N - 1] << "\n";

    return 0;
}

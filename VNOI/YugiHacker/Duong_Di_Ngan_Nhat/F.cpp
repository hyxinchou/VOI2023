#include <bits/stdc++.h>

using i64 = long long;

int N, M, C, cost[15], d[3 * (2222 * 10 + 10)], answer;
std::vector<std::vector<std::pair<int, int>>> E(3 * (2222 * 10 + 10));

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> M >> N;
    for (int i = 0; i < 2 * M; ++i) {
        if (~i & 1) {
            if (!i) {
                for (int j = 0; j < N; ++j) {
                    std::cin >> cost[j];
                }
            } else {
                for (int j = 0; j < N; ++j) {
                    std::cin >> C;
                    E[((i / 2) - 1) * N + j].push_back(std::make_pair(C, (i / 2) * N + j));
                    E[(i / 2) * N + j].push_back(std::make_pair(C, ((i / 2) - 1) * N + j));
                    // std::cerr << ((i / 2) - 1) * N + j << " -> " << (i / 2) * N + j << " : " << C << "\n";
                }
            }
        } else {
            for (int j = 0; j < N - 1; ++j) {
                std::cin >> C;
                E[(i / 2) * N + j].push_back(std::make_pair(C, (i / 2) * N + j + 1));
                E[(i / 2) * N + j + 1].push_back(std::make_pair(C, (i / 2) * N + j));
                // std::cerr << (i / 2) * N + j << " -> " << (i / 2) * N + j + 1 << " : " << C << "\n";
                // std::cerr << (i / 2) * N + j + 1 << " -> " << (i / 2) * N + j << " : " << C << "\n";
            }
        }
    }
    std::function<int(int)> Dijkstra = [&](int root) {
        memset(d, 0x3f3f, sizeof(d));
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.push(std::make_pair(0, root));
        d[root] = 0;
        while (pq.size()) {
            int len = pq.top().first;
            int to = pq.top().second;
            pq.pop();
            if (d[to] != len) {
                continue;
            }
            for (int i = 0; i < int(E[to].size()); ++i) {
                if (d[E[to][i].second] > d[to] + E[to][i].first) {
                    d[E[to][i].second] = d[to] + E[to][i].first;
                    pq.push(std::make_pair(d[E[to][i].second], E[to][i].second));
                }
            }
        }
        return cost[root] + d[(M - 1) * N + N - 1];
    };
    answer = int(1e9 + 7);
    for (int i = 0; i < N; ++i) {
        answer = std::min(answer, Dijkstra(i));
    }
    std::cout << answer << "\n";

    return 0;
}

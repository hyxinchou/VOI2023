#include <bits/stdc++.h>

using i64 = long long;

int N, M, K, X, Y, C;
double d[1005][15];
std::vector<std::vector<std::pair<double, int>>> E(1005);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        std::cin >> X >> Y >> C;
        --X, --Y;
        E[X].push_back(std::make_pair(C, Y));
        E[Y].push_back(std::make_pair(C, X));
    }
    memset(d, 0x7f, sizeof(d));
    std::priority_queue<std::pair<double, std::pair<int, int>>, std::vector<std::pair<double, std::pair<int, int>>>, std::greater<>> pq;
    d[0][0] = 0;
    pq.push(std::make_pair(0, std::make_pair(0, 0)));
    while (pq.size()) {
        double len = pq.top().first;
        int to = pq.top().second.first;
        int k = pq.top().second.second;
        pq.pop();
        if (d[to][k] != len) {
            continue;
        }
        for (int i = 0; i < int(E[to].size()); ++i) {
            if (d[E[to][i].second][k] > d[to][k] + E[to][i].first) {
                d[E[to][i].second][k] = d[to][k] + E[to][i].first;
                pq.push(std::make_pair(d[E[to][i].second][k], std::make_pair(E[to][i].second, k)));
            }
            for (int j = 0; j < K - k; ++j) {
                if (d[E[to][i].second][k + j + 1] > d[to][k] + double(E[to][i].first / double(std::pow(2, j + 1)))) {
                    d[E[to][i].second][k + j + 1] = d[to][k] + double(E[to][i].first / double(std::pow(2, j + 1)));
                    // std::cout << E[to][i].first << " " << std::pow(2, j + 1) << double(E[to][i].first / double(std::pow(2, j + 1))) << "\n";
                    pq.push(std::make_pair(d[E[to][i].second][k + j + 1], std::make_pair(E[to][i].second, k + j + 1)));
                }
            }
        }
    }
    std::cout << std::fixed << std::setprecision(2) << d[N - 1][K] << "\n";

    return 0;
}

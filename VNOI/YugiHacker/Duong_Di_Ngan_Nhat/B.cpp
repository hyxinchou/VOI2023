#include <bits/stdc++.h>

using i64 = long long;

i64 ways[30005], ways2[30005];
int N, M, X, Y, D, d[30005], d2[30005];
std::vector<std::vector<std::pair<int, int>>> E(30005);
std::vector<int> answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        std::cin >> X >> Y >> D;
        --X, --Y;
        E[X].push_back(std::make_pair(D, Y));
        E[Y].push_back(std::make_pair(D, X));
    }
    std::memset(d, -1, sizeof(d));
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;
    pq.push({0, 0, 0});
    ways[0] = 1;
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
    std::memset(d2, -1, sizeof(d2));
    pq.push({0, N - 1, N - 1});
    ways2[N - 1] = 1;
    while (pq.size()) {
        int cost = pq.top()[0];
        int to = pq.top()[1];
        int parent = pq.top()[2];
        pq.pop();
        if (d2[to] == -1) {
            d2[to] = cost;
            ways2[to] = ways2[parent];
            for (int i = 0; i < int(E[to].size()); ++i) {
                if (d2[E[to][i].second] == -1) {
                    pq.push({cost + E[to][i].first, E[to][i].second, to});
                }
            }
        } else if (d2[to] == cost) {
            ways2[to] += ways2[parent];
        }
    }
    for (int i = 1; i < N - 1; ++i) {
        if (d[i] + d2[i] != d[N - 1]) {
            answer.push_back(i);
        } else if (d[i] + d2[i] == d[N - 1] && ways[i] * ways2[i] != ways[N - 1]) {
            answer.push_back(i);
        }
    }
    std::cout << int(answer.size()) << "\n";
    for (int i = 0; i < int(answer.size()); ++i) {
        std::cout << answer[i] + 1 << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>

using i64 = long long;

int N, M, K, S, T, D, C, L, U, V, Q;
i64 d[2][10005], answer;
std::vector<std::vector<std::vector<std::pair<i64, int>>>> E(2, std::vector<std::vector<std::pair<i64, int>>> (10005));

void solve() {
    std::cin >> N >> M >> K >> S >> T;
    --S, --T;
    for (int i = 0; i < N; ++i) {
        E[0][i].clear();
        E[1][i].clear();
    }
    for (int i = 0; i < M; ++i) {
        std::cin >> D >> C >> L;
        --D, --C;
        E[0][D].push_back(std::make_pair(L, C));
        E[1][C].push_back(std::make_pair(L, D));
    }
    std::function<void(int)> Dijkstra = [&](int root) {
        int ii = (root == S ? 0 : 1);
        for (int i = 0; i < N; ++i) {
            d[ii][i] = int(1e17);
        }
        std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<>> pq;
        pq.push(std::make_pair(0, root));
        d[ii][root] = 0;
        while (pq.size()) {
            i64 len = pq.top().first;
            int to = pq.top().second;
            pq.pop();
            if (d[ii][to] != len) {
                continue;
            }
            for (int i = 0; i < int(E[ii][to].size()); ++i) {
                if (d[ii][E[ii][to][i].second] > d[ii][to] + 1LL * E[ii][to][i].first) {
                    d[ii][E[ii][to][i].second] = d[ii][to] + 1LL * E[ii][to][i].first;
                    pq.push(std::make_pair(d[ii][E[ii][to][i].second], E[ii][to][i].second));
                }
            }
        }
    };
    Dijkstra(S);
    Dijkstra(T);
    answer = i64(1e17);
    for (int i = 0; i < K; ++i) {
        std::cin >> U >> V >> Q;
        --U, --V;
        // std::cout << U + 1 << " " << V + 1 << " " << d[0][U] << " " << d[1][V] << " " << d[0][V] << " " << d[1][U] << "\n";
        answer = std::min(answer, std::min(d[0][U] + d[1][V], d[0][V] + d[1][U]) + Q);
    }
    answer = std::min(answer, d[0][T]);
    if (answer == int(1e17)) {
        answer = -1;
    }
    std::cout << answer << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Tests;
    std::cin >> Tests;
    while (Tests--) {
        solve();
    }

    return 0;
}

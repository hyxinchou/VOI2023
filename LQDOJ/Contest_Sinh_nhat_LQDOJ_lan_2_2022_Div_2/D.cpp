#include <bits/stdc++.h>

using i64 = long long;

bool visited[25][25];
int N, M, A, B, f[25][25], answer;
char C;
std::vector<std::vector<std::pair<char, int>>> E(25);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        std::cin >> A >> B >> C;
        --A, --B;
        E[A].push_back(std::make_pair(C, B));
        E[B].push_back(std::make_pair(C, A));
    }
    answer = int(1e9);
    memset(f, 0x3f, sizeof(f));
    memset(visited, false, sizeof(visited));
    std::queue<std::pair<int, int>> que;
    que.push(std::make_pair(0, 1));
    visited[0][1] = true;
    f[0][1] = 0;
    while (que.size()) {
        int u = que.front().first;
        int v = que.front().second;
        que.pop();
        if (u == v) {
            answer = std::min(answer, f[u][v]);
            continue;
        }
        for (int i = 0; i < int(E[u].size()); ++i) {
            for (int j = 0; j < int(E[v].size()); ++j) {
                if (E[u][i].first == E[v][j].first && !visited[E[u][i].second][E[v][j].second]) {
                    visited[E[u][i].second][E[v][j].second] = true;
                    f[E[u][i].second][E[v][j].second] = f[u][v] + 2;
                    que.push(std::make_pair(E[u][i].second, E[v][j].second));
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < int(E[i].size()); ++j) {
            int u = i;
            int v = E[i][j].second;
            answer = std::min(answer, f[u][v] + 1);
            answer = std::min(answer, f[v][u] + 1);
        }
    }
    if (answer == int(1e9)) {
        answer = -1;
    }
    std::cout << answer << "\n";

    return 0;
}

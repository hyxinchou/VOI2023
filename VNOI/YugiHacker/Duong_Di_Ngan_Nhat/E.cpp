#include <bits/stdc++.h>

using i64 = long long;

int K, N, R, S, D, L, T, d[105][10005], answer;
std::vector<std::vector<std::array<int, 3>>> E(105);

void solve() {
    std::cin >> K >> N >> R;
    for (int i = 0; i < N; ++i) {
        E[i].clear();
    }
    for (int i = 0; i < R; ++i) {
        std::cin >> S >> D >> L >> T;
        --S, --D;
        E[S].push_back({L, T, D});
    }
    memset(d, 0x3f3f, sizeof(d));
    d[0][0] = 0;
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;
    pq.push({0, 0, 0});
    while (pq.size()) {
        int len = pq.top()[0];
        int to = pq.top()[1];
        int cost = pq.top()[2];
        pq.pop();
        if (d[to][cost] != len) {
            continue;
        }
        for (int i = 0; i < int(E[to].size()); ++i) {
            if (cost + E[to][i][1] <= K && d[E[to][i][2]][cost + E[to][i][1]] > d[to][cost] + E[to][i][0]) {
                d[E[to][i][2]][cost + E[to][i][1]] = d[to][cost] + E[to][i][0];
                pq.push({d[E[to][i][2]][cost + E[to][i][1]], E[to][i][2], cost + E[to][i][1]});
            }
        }
    }
    answer = int(1e9 + 7);
    for (int i = 0; i <= K; ++i) {
        answer = std::min(answer, d[N - 1][i]);
    }
    if (answer == int(1e9 + 7)) {
        answer = -1;
    }
    std::cout << answer << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

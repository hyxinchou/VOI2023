#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        i64 H;
        std::cin >> H;
        std::vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }
        std::vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> B[i];
        }
        std::vector<int> P(N);
        std::iota(P.begin(), P.end(), 0);
        std::sort(P.begin(), P.end(), [&](const auto &x, const auto &y) {
            return B[x] > B[y];
        });
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>> pq;
        std::deque<int> dq;
        for (int i = 0; i < N; ++i) {
            dq.push_back(P[i]);
        }
        int ans = 0;
        i64 h = std::accumulate(A.begin(), A.end(), 0LL);
        while (dq.size()) {
            int now = dq.front();
            dq.pop_front();
            h -= A[now];
            if (h + B[now] >= H) {
                pq.push(std::make_pair(A[now], now));
            } else {
                bool con = false;
                while (pq.size()) {
                    auto [hh, nn] = pq.top();
                    pq.pop();
                    dq.push_back(nn);
                    h += hh;
                    if (h + B[now] >= H) {
                        pq.push(std::make_pair(A[now], now));
                        con = true;
                        break;
                    }
                }
                if (!con) {
                    break;
                }
            }
            ans = std::max(ans, int(pq.size()));
        }
        std::cout << ans << "\n";
    }

    return 0;
}

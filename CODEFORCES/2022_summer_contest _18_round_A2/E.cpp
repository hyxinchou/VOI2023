#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("banhkhuc.inp", "r", stdin);
    freopen("banhkhuc.out", "w", stdout);

    int N, K; cin >> N >> K;
    vector<vector<i64>> d(N, vector<i64> (N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> d[i][j];
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    vector<int> q(K);
    for (int i = 0; i < K; ++i) {
        cin >> q[i];
        --q[i];
    }
    vector<int> p(K, 0);
    i64 inf = i64(1e18);
    vector<i64> dp(1 << K, inf)
    for (int mask = 0; mask < (1 << K); ++mask) {
        for (int i = 0; i < N; ++i) {
            if (mask >> i & 1) {
                for (int j = 0; j < N; ++j) {
                    if (!(mask >> j & 1)) {
                        
                    }
                }
            }
        }
    }

    return 0;
}

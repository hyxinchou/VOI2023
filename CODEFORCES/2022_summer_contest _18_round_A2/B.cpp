#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // freopen("euclid.inp", "r", stdin);
    // freopen("euclid.out", "w", stdout);

    int N; cin >> N;
    vector<pair<i64, i64>> A(N);
    for (auto &[x, y] : A) {
        cin >> x >> y;
    }
    vector<pair<i64, i64>> Max(N);
    for (int i = 0; i < N; ++i) {
        i64 Maxf = 0;
        i64 Maxs = 0;
        for (int j = 0; j < N; ++j) {
            auto [x1, y1] = A[i];
            auto [x2, y2] = A[j];
            i64 d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            if (Maxf < d) {
                Maxs = Maxf;
                Maxf = d;
            } else if (d < Maxf && d > Maxs) {
                Maxs = d;
            }
        }
        Max[i] = make_pair(Maxf, Maxs);
    }
    for (auto [x, y] : Max) {
        cout << x << " " << y << "\n";
    }
    set<i64> Set;
    multiset<i64> MSet;
    for (int i = 0; i < N; ++i) {
        auto [x, y] = Max[i];
        Set.insert(x);
        Set.insert(y);
        MSet.insert(x);
        MSet.insert(y);
    }
    for (int i = 0; i < N; ++i) {
        auto [x, y] = Max[i];
        MSet.erase(MSet.find(x));
        if (!MSet.count(x)) {
            Set.erase(x);
        }
        MSet.erase(MSet.find(y));
        if (!MSet.count(y)) {
            Set.erase(y);
        }
        auto ans = --Set.end();
        cout << fixed << setprecision(12) << sqrt(*(--ans)) << "\n";
        MSet.insert(x);
        MSet.insert(y);
        Set.insert(x);
        Set.insert(y);
    }

    return 0;
}

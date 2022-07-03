#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("squares.inp", "r", stdin);
    freopen("squares.out", "w", stdout);

    vector<i64> ar;
    for (i64 i = 1; i * i <= 10000000000; ++i) {
        i64 c = i * i;
        set<int> Unq;
        int cnt = 0;
        while (c) {
            Unq.insert(c % 10);
            ++cnt;
            c /= 10;
        }
        if (int(Unq.size()) == cnt) {
            ar.push_back(i * i);
        }
    }
    int K; cin >> K;
    if (K > int(ar.size())) {
        cout << "-1\n";
    } else {
        cout << ar[K - 1] << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, m;
long long res = -1e18, s[55], mn_prefix[55], mx_prefix[55], mx[55];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1, k; i <= n; ++ i) {
        cin >> k;
        mx[i] = -1e9;
        for (int j = 1, x, pre = 0; j <= k; ++ j) {
            cin >> x;
            pre += x;
            mx[i] = max(mx[i], (long long)pre); // max subarray
            pre = max(0, pre); // kadane
            s[i] += x; // sum of small array
            mn_prefix[i] = min(mn_prefix[i], s[i]); // min prefix
            mx_prefix[i] = max(mx_prefix[i], s[i]); // max prefix
        }
    }
    long long sum = 0, mn = 0;
    for (int i = 1; i <= m; ++ i) {
        int x;
        cin >> x;
        // same small array
        res = max(res, mx[x]);

        // different small array
        if (i > 1 && mx_prefix[x] > 0) {
            long long mx = sum + mx_prefix[x];
            res = max(res, mx - mn);
        }
        // prepare for step i + 1
        mn = min(mn, sum + mn_prefix[x]); // min prefix if we used i small array before
        sum += s[x]; // sum of i small array
    }
    cout << res;
    return 0;
}

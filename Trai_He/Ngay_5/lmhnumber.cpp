#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    std::cin >> S;
    int n = int(S.size());
    std::vector<bool> change(n, false);
    std::vector<std::vector<int>> nBlock(11, std::vector<int> (n, 0));
    int cnt = 0;
    std::set<int> Unq;
    for (int i = n - 1; ~i; --i) {
        Unq.insert(int(S[i] - '0'));
        ++nBlock[int(S[i] - '0')][cnt];
        if (int(Unq.size()) == 10) {
            ++cnt;
            Unq.clear();
            change[i] = true;
        }
    }
    int min = 9;
    std::string ans = "";
    if (Unq.empty()) {
        ans += '1';
    } else {
        if (!Unq.count(0) && int(Unq.size()) == 9) {
            min = 0;
            ans += '1';
        } else {
            for (int i = 1; i < 10; ++i) {
                if (!Unq.count(i)) {
                    ans += char(i + '0');
                    break;
                }
            }
        }
    }
    char last = ans[0];
    bool f = false;
    for (int i = 0; i < n; ++i) {
        if (change[i]) {
            f = true;
            --cnt;
        }
        --nBlock[int(S[i] - '0')][cnt];
        if (f && !nBlock[int(S[i] - '0')][cnt]) {
            min = std::min(min, int(S[i] - '0'));
        }
        if (last == S[i]) {
            ans += char(min + '0');
            last = char(min + '0');
            min = 9;
            f = false;
        }
    }
    std::cout << ans << "\n";

    return 0;
}

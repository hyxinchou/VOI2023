#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string SA, SB, SC;
    std::cin >> SA >> SB >> SC;
    int cur = 0;
    while (true) {
        if (!cur) {
            if (SA.empty()) {
                std::cout << "A\n";
                return 0;
            } else {
                cur = int(SA[0] - 'a');
                SA.erase(SA.begin());
            }
        }
        if (cur == 1) {
            if (SB.empty()) {
                std::cout << "B\n";
                return 0;
            } else {
                cur = int(SB[0] - 'a');
                SB.erase(SB.begin());
            }
        }
        if (cur == 2) {
            if (SC.empty()) {
                std::cout << "C\n";
                return 0;
            } else {
                cur = int(SC[0] - 'a');
                SC.erase(SC.begin());
            }
        }
    }

    return 0;
}

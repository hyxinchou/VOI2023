#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;
    std::string S;
    std::cin >> S;
    while (Q--) {
        int l, r;
        std::cin >> l >> r;
        --l, --r;
        std::stack<char> Stack;
        int ans = 0;
        bool last = 0;
        for (int i = l; i <= r; ++i) {
            if (Stack.empty()) {
                Stack.push(S[i]);
                last = 0;
            } else if (S[i] == '(') {
                Stack.push(S[i]);
                last = 0;
            } else if (S[i] == ')') {
                if (Stack.size() && Stack.top() == '(') {
                    Stack.pop();
                    if (last) {
                        continue;
                    } else {
                        last = 1;
                        ++ans;
                    }
                }
            }
        }
        std::cout << ans << "\n";
    }

    return 0;
}

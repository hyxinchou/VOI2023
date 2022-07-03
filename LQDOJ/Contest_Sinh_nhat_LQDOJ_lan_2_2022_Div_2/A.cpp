#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::string S;
        std::cin >> S;
        std::cout << char(std::toupper(S[0]));
    }

    return 0;
}

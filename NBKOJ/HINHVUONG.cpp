#include <bits/stdc++.h>

std::pair<int, int> A[4];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (int i = 0; i < 4; ++i) {
        std::cin >> A[i].first >> A[i].second;
    }
    std::sort(A, A + 4);
    if (A[0].first == A[1].first && A[2].first == A[3].first) {
        if (A[0].second == A[2].second && A[1].second == A[3].second) {
            if (A[2].first - A[0].first == A[1].second - A[0].second) {
                std::cout << 1LL * (A[2].first - A[0].first) * (A[2].first - A[0].first) << "\n";
                return 0;
            }
        }
    }
    std::cout << "-1\n";
    
    return 0;
}
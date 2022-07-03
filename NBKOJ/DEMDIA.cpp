#include <bits/stdc++.h>

using i64 = long long;

i64 N, A, B, answer;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> N >> A >> B;
    int answer = 0;
    while (N > 0) {
        N -= A;
        ++answer;
        A += B;
    }
    std::cout << answer << "\n";
    
    
    return 0;
}
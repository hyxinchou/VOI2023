#include <bits/stdc++.h>

using i64 = long long;

int N, A[105][105], answer;
bool visited[105];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> A[i][j];
            if (!A[i][j]) {
                A[i][j] = int(1e9);
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        A[i][i] = 0;
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][k] != int(1e9) && A[k][j] != int(1e9)) {
                    A[i][j] = std::min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
    }
    memset(visited, false, sizeof(visited));
    answer = 0;
    int now = 0;
    visited[0] = true;
    visited[N - 1] = true;
    while (true) {
        int min = int(1e9);
        int choose = -1;
        for (int i = 0; i < N - 1; ++i) {
            if (now != i && !visited[i] && A[now][i] < min) {
                min = A[now][i];
                choose = i;
            }
        }
        if (choose == -1) {
            break;
        }
        answer += min;
        visited[choose] = true;
        now = choose;
    }
    std::cout << answer + A[now][N - 1] << "\n";

    return 0;
}

#include <bits/stdc++.h>

using i64 = long long;

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int N, M; cin >> N >> M;
  vector<vector<int>> A(M, vector<int> (N, 0));
  for (int i = 0; i < M; ++i) {
    int K; cin >> K;
    for (int j = 0; j < K; ++j) {
      int a; cin >> a;
      if (a > 0) {
        A[i][a - 1] = 1;
      } else {
        A[i][abs(a) - 1] = 2;
      }
    }
  }
  auto sub1 = [&]() -> void {
    vector<pair<int, int>> p(M);
    for (int i = 0; i < M; ++i) {
      int mask = 0;
      int mask2 = 0;
      for (int j = 0; j < N; ++j) {
        if (A[i][j] == 1) {
          mask |= (1 << j);
        } else if (A[i][j] == 2) {
          mask2 |= (1 << j);
        }
      }
      p[i] = make_pair(mask, mask2);
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << N); ++mask) {
      bool ok = true;
      for (int i = 0; i < M; ++i) {
        if (mask & p[i].first || (~mask & p[i].second)) {
          continue;
        } else {
          ok = false;
        }
      }
      if (ok) {
        ++ans;
      }
    }
    cout << ans << "\n";
  };
  if (N <= 20) {
    sub1();
  }
  return 0;
}

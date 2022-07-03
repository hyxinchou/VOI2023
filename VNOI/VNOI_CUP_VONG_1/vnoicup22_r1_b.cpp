#include <bits/stdc++.h>

using i64 = long long;

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int N; cin >> N;
  vector<int> A(N);
  for (auto &a : A) {
    cin >> a;
  }
  auto sub1 = [&]() -> void {
    for (int i = 0; i < N; ++i) {
      int ans = 0;
      for (int j = 0; j < N; ++j) {
        for (int k = j + 1; k < N; ++k) {
          if (i != j && i != k) {
            int c = __gcd(A[j], A[k]);
            if (c > A[i]) {
              int f = c / A[i];
              if (c <= f * A[i] && c > (f - 1) * A[i] && ~f & 1) {
                ++ans;
              }
            }
          }
        }
      }
      cout << ans << " ";
    }
  };
  if (N <= 100) {
    sub1();
  }

  return 0;
}

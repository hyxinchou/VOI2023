#include <bits/stdc++.h>

using i64 = long long;

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int N; cin >> N;
  vector<int> A(N), B(N);
  for (auto &a : A) {
    cin >> a;
  }
  for (auto &b : B) {
    cin >> b;
  }
  if (A.back() == B[0]) {
    cout << string(N - 1, 'a') << string(N, 'b') << "a\n";
  } else {
    cout << string(N, 'a') << string(N, 'b') << "\n";
  }

  return 0;
}

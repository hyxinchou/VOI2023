#include <bits/stdc++.h>

using i64 = long long;

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int N; cin >> N;
  vector<string> S(N);
  for (auto &s : S) {
    cin >> s;
  }
  auto sub1 = [&]() -> void {
    vector<set<int>> A(26);
    for (auto s : S) {
      A[int(s[0] - 'a')].insert(int(s.size()));
    }
    for (auto s : S) {
      int siz = int(s.size());
      while (A[int(s[0] - 'a')].count(siz)) {
        ++siz;
      }
      cout << siz - int(s.size()) << "\n";
    }
  };
  sub1();

  return 0;
}

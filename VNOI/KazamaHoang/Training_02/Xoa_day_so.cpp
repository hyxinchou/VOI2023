#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, X; cin >> N >> X;
	vector<int> A(N);
	for (auto &v : A) {
		cin >> v;
	}
	auto sub2 = [&]() -> void {
		auto check = [&](int l, int r) -> bool {
			vector<int> nA;
			for (auto v : A) {
				if (v < l || v > r) {
					nA.push_back(v);
				}
			}
			return is_sorted(nA.begin(), nA.end());
		};
		int ans = 0;
		for (int l = 1, r = 1; l <= X; ++l) {
			r = max(r, l);
			while (r <= X && !check(l, r)) {
				++r;
			}
			ans += X - r + 1;
		}
		cout << ans << "\n";
	};
	auto sub3 = [&]() -> void {
		#define mx second
		#define mn first
		constexpr int inf = int(1e9);
		vector<pair<int, int>> Info(X + 2, make_pair(inf, -inf));
		for (int i = 0; i < N; ++i) {
			Info[A[i]].mx = max(Info[A[i]].mx, i);
			Info[A[i]].mn = min(Info[A[i]].mn, i);
		}
		int Left = *min_element(A.begin(), A.end());
		int Pre = Left;
		for (int i = Left + 1; i <= X; ++i) {
			if (Info[i] != make_pair(inf, -inf)) {
				if (Info[i].mn > Info[Pre].mx) {
					Pre = i;
				} else {
					break;
				}
			}
			++Left;
		}
		int Right = *max_element(A.begin(), A.end());
		Pre = Right;
		for (int i = Right - 1; i > 0; --i) {
			if (Info[i] != make_pair(inf, -inf)) {
				if (Info[i] != make_pair(inf, -inf) && Info[i].mx < Info[Pre].mn) {
					Pre = i;
				} else {
					break;
				}
			}
			--Right;
		}
		Info[0].mx = -1;
		for (int i = 1; i <= X; ++i) {
			if (Info[i].mx == -inf) {
				Info[i].mx = Info[i - 1].mx;
			}
		}
		Info[X + 1].mn = inf;
		for (int i = X; ~i; --i) {
			if (Info[i].mn == inf) {
				Info[i].mn = Info[i + 1].mn;
			}
		}
		int ans = 0;
		Info[X + 1] = make_pair(inf, -inf);
		for (int l = 1, r = Right - 1; l <= Left + 1; ++l) {
			r = max(r, l);
			while (r <= X && r >= Right - 1 && Info[l - 1].mx > Info[r + 1].mn) {
				++r;
			}
			ans += X - r + 1;
		}
		cout << ans << "\n";
	};
	if (N <= 1000) {
		sub2();
	} else {
		sub3();
	}
	
	return 0;
}
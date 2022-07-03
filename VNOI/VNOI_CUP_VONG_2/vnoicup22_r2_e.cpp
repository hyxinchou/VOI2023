#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        std::string S;
        std::cin >> S;

        auto sub1 = [&]() -> void {
            int ans = 0;
            int siz = int(S.size());
            if (siz >= 2) {
                for (int i = 0; i < siz - 1; ++i) {
                    std::vector<std::string> f(2);
                    f[0] = S.substr(0, i + 1);
                    f[1] = S.substr(i + 1);
                    std::string f2 = S;
                    std::vector<int> p(2);
                    std::iota(p.begin(), p.end(), 0);
                    do {
                        std::string r = "";
                        for (auto v : p) {
                            r += f[v];
                        }
                        f2 = std::min(f2, r);
                    } while (std::next_permutation(p.begin(), p.end()));
                    if (f2 == S) {
                        ++ans;
                    }
                }
            }
            if (siz >= 3) {
                for (int i = 0; i <= siz; ++i) {
                    for (int j = 0; j <= siz; ++j) {
                        if (i + 1 + j + 1 < siz) {
                            std::vector<std::string> f(3);
                            f[0] = S.substr(0, i + 1);
                            f[1] = S.substr(i + 1, j + 1);
                            f[2] = S.substr(i + 1 + j + 1);
                            std::string f3 = S;
                            std::vector<int> p(3);
                            std::iota(p.begin(), p.end(), 0);
                            do {
                                std::string r = "";
                                for (auto v : p) {
                                    r += f[v];
                                }
                                f3 = std::min(f3, r);
                            } while (std::next_permutation(p.begin(), p.end()));
                            if (f3 == S) {
                                ++ans;
                            }
                        }
                    }
                }
            }
            if (siz >= 4) {
                for (int i = 0; i <= siz; ++i) {
                    for (int j = 0; j <= siz; ++j) {
                        for (int k = 0; k <= siz; ++k) {
                            if (i + 1 + j + 1 + k + 1 < siz) {
                                std::vector<std::string> f(4);
                                f[0] = S.substr(0, i + 1);
                                f[1] = S.substr(i + 1, j + 1);
                                f[2] = S.substr(i + 1 + j + 1, k + 1);
                                f[3] = S.substr(i + 1 + j + 1 + k + 1);
                                std::string f4 = S;
                                std::vector<int> p(4);
                                std::iota(p.begin(), p.end(), 0);
                                do {
                                    std::string r = "";
                                    for (auto v : p) {
                                        r += f[v];
                                    }
                                    f4 = std::min(f4, r);
                                } while (std::next_permutation(p.begin(), p.end()));
                                if (f4 == S) {
                                    ++ans;
                                }
                            }
                        }
                    }
                }
            }
            if (siz >= 5) {
                for (int i = 0; i <= siz; ++i) {
                    for (int j = 0; j <= siz; ++j) {
                        for (int k = 0; k <= siz; ++k) {
                            for (int l = 0; l <= siz; ++l) {
                                if (i + 1 + j + 1 + k + 1 + l + 1 < siz) {
                                    std::vector<std::string> f(5);
                                    f[0] = S.substr(0, i + 1);
                                    f[1] = S.substr(i + 1, j + 1);
                                    f[2] = S.substr(i + 1 + j + 1, k + 1);
                                    f[3] = S.substr(i + 1 + j + 1 + k + 1, l + 1);
                                    f[4] = S.substr(i + 1 + j + 1 + k + 1 + l + 1);
                                    std::string f5 = S;
                                    std::vector<int> p(5);
                                    std::iota(p.begin(), p.end(), 0);
                                    do {
                                        std::string r = "";
                                        for (auto v : p) {
                                            r += f[v];
                                        }
                                        f5 = std::min(f5, r);
                                    } while (std::next_permutation(p.begin(), p.end()));
                                    if (f5 == S) {
                                        ++ans;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            std::cout << ans << "\n";
        };

        if (int(S.size()) <= 5) {
            sub1();
        }
    }

    return 0;
}

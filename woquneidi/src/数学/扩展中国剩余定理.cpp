#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

array<i64, 3> exgcd(i64 a, i64 b) {
    if(b == 0) {
        return {a, 1, 0};
    }
    auto [gd, x, y] = exgcd(b, a % b);
    return {gd, y, x - a / b * y};
}

i64 EXCRT(vector<pair<i64, i64>> &v) {
    i64 M = 1, ans = 0;
    
    for(const auto &[m, r] : v) {
        i64 c = ((r - ans) % m + m) % m;
        auto [gd, x, y] = exgcd(M, m);
        i64 x0 = (__int128)x * (c / gd) % (m / gd);
        i64 tmp = M * (m / gd);
        ans = (ans + (__int128)x0 * M % tmp) % tmp;
        M = tmp;
    }
    return (ans % M + M) % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<std::pair<i64, i64>> v(n);
    for(auto &[m, r] : v) {
        std::cin >> m >> r;
    }
    cout << EXCRT(v) << '\n';
    return 0;
}
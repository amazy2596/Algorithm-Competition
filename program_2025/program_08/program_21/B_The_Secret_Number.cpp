// Problem: B. The Secret Number
// URL: https://codeforces.com/contest/2132/problem/B
// Author: amazy
// Date: 2025-08-21 22:48:42

// Problem: B. The Secret Number  B. 秘密数字
// URL: https://codeforces.com/contest/2132/problem/B
// Author: amazy
// Date: 2025-08-21 22:39:47

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

void solve()
{
    i64 n;
    cin >> n;

    vector<i64> ans;
    for (int k = 1; k <= 18; k++)
    {
        i64 tmp = (i64)pow(10, k) + 1;
        if (n % tmp == 0)
        {
            ans.push_back(n / tmp);
        }
    }

    if (ans.empty())
    {
        cout << "0\n";
        return;
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto v : ans) cout << v << ' ';
    cout << "\n";
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
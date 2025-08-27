// Problem: 小苯的数字折叠
// URL: https://ac.nowcoder.com/acm/contest/116002/B
// Author: amazy
// Date: 2025-08-27 14:53:13

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



void solve()
{
    i64 n, k;
    cin >> n >> k;

    auto check = [&](i64 x)
    {
        string s = to_string(x);
        for (int i = 0, j = s.length() - 1; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }

        return true;
    };

    if (check(n))
    {
        cout << n << " " << 0 << "\n";
        return;
    }

    for (int i = 1; i <= k; i++)
    {
        string tmp = to_string(n);
        reverse(tmp.begin(), tmp.end());
        while (tmp.size() && tmp.back() == '0')
            tmp.pop_back();

        i64 x = 0;
        for (int j = 0; j < tmp.length(); j++)
            x = (x * 10 + (tmp[j] - '0'));
        n += x;

        if (check(n))
        {
            cout << n << " " << i << "\n";
            return;
        }
    }

    cout << n << " " << -1 << "\n";
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
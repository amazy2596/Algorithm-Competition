// Problem: Hash
// URL: https://ac.nowcoder.com/acm/contest/120454/E
// Author: amazy
// Date: 2025-11-12 20:14:05

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    string s;
    while (cin >> s >> mod)
    {
        int n = s.length();
        s = " " + s;
        vector<int> t(n + 1);
        for (int i = 1; i <= n; i++) t[i] = s[i] - 'a';
        t[6] += mod;
        for (int i = n; i >= 1; i--)
        {
            t[i - 1] += t[i] / 26;
            t[i] %= 26;
        }

        if (t[0]) cout << "-1\n";
        else 
        {
            for (int i = 1; i <= n; i++)
            {
                cout << char(t[i] + 'a');
            }
            cout << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
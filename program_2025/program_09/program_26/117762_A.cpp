// Problem: Kato_Shoko
// URL: https://ac.nowcoder.com/acm/contest/117762/A
// Author: amazy
// Date: 2025-09-26 19:23:26

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
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, int> need;
    need['K'] = 1;
    need['a'] = 1;
    need['t'] = 1;
    need['o'] = 3;
    need['_'] = 1;
    need['S'] = 1;
    need['h'] = 1;
    need['k'] = 1;

    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[s[i]]++;

    int ans = 0;
    for (auto [key, val] : mp)
    {
        if (!need.contains(key))
            ans += val;
        else 
        {
            if (val < need[key]) 
            {
                cout << "NO\n";
                return;
            }

            ans += val - need[key];
            need.erase(key);
        }
    }
    if (need.size())
    {
        cout << "NO\n";
        return;
    }

    cout << "YES " << ans << "\n";
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
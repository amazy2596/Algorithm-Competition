// Problem: 牛牛的串串
// URL: https://ac.nowcoder.com/acm/contest/116657/A
// Author: amazy
// Date: 2025-09-05 20:29:28

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
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[s[i] - 'a']++;

    for (int i = 1; i < 26; i++)
    {
        if (mp.find(i) == mp.end() || mp.find(i - 1) == mp.end())
            continue;
        if (mp[i] != mp[i - 1] + 1)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
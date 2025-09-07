// Problem: D. Replace with Occurrences
// URL: https://codeforces.com/contest/2137/problem/D
// Author: amazy
// Date: 2025-09-07 22:54:35

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
    vector<int> b(n);
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; ++i) 
    {
        cin >> b[i];
        pos[b[i]].push_back(i);
    }

    bool ok = true;
    vector<int> a(n);
    int color = 0;

    for (int s = 1; s <= n; s++) 
    {
        int cnt = pos[s].size();
        if (cnt % s != 0) 
        {
            ok = false; 
            break; 
        }
        for (int i = 0; i < cnt; i += s) 
        {
            color++;
            for (int j = 0; j < s; ++j)
                a[pos[s][i + j]] = color;
        }
    }

    if (!ok)
        cout << -1 << '\n';
    else 
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << (i + 1 == n ? '\n' : ' ');
    }
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
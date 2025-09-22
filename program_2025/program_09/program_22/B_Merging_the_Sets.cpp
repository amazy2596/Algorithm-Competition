// Problem: B. Merging the Sets
// URL: https://codeforces.com/contest/2146/problem/B
// Author: amazy
// Date: 2025-09-22 17:28:20

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
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        a[i].resize(l);
        for (int j = 0; j < l; j++)
        {
            cin >> a[i][j];
            mp[a[i][j]]++;
        }
    }

    int ans = 0;
    if (mp.size() == m)
        ans++;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            mp[a[i][j]]--;
            if (mp[a[i][j]] == 0)
                mp.erase(a[i][j]);
        }

        if (mp.size() == m)
            ans++;

        for (int j = 0; j < a[i].size(); j++)
            mp[a[i][j]]++;
    }

    cout << (ans >= 3 ? "YES\n" : "NO\n");
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
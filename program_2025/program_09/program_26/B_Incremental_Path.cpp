// Problem: B. Incremental Path
// URL: https://codeforces.com/contest/2151/problem/B
// Author: amazy
// Date: 2025-09-26 10:49:46

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
    string s;
    cin >> s;

    map<int, int> ans;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        ans[x]++;
    }

    int pos = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            pos++;
            ans[pos]++;
        }
        else 
        {
            pos++;
            while (ans.contains(pos))
                pos++;
            ans[pos]++;
            while (ans.contains(pos))
                pos++;
        }
    }

    cout << ans.size() << "\n";
    for (auto [key, val] : ans)
        cout << key << " ";
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
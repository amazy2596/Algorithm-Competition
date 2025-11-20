// Problem: D. MAD Interactive Problem
// URL: https://codeforces.com/contest/2160/problem/D
// Author: amazy
// Date: 2025-10-27 18:05:23

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
    vector<int> cur;

    auto query = [&]()
    {
        cout << "? " << cur.size() << " ";
        for (auto x : cur) cout << x << " ";
        cout << endl;
        int res;
        cin >> res;
        return res;
    };

    vector<int> ans(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        cur.push_back(i);
        int res = query();
        if (res > 0)
        {
            ans[i] = res;
            cur.pop_back();
        }
    }
    cur.clear();
    for (int i = 1; i <= 2 * n; i++)
    {
        if (ans[i] != 0)
        {
            cur.push_back(i);
        }
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        if (ans[i] == 0)
        {
            cur.push_back(i);
            ans[i] = query();
            cur.pop_back();
        }
    }

    cout << "! ";
    for (int i = 1; i <= 2 * n; i++)
        cout << ans[i] << " ";
    cout << endl;
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
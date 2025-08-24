// Problem: C. The Nether
// URL: https://codeforces.com/contest/2133/problem/C
// Author: amazy
// Date: 2025-08-24 22:45:47

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

    vector<vector<int>> a(n + 1);
    auto query = [&](int x, vector<int> &v)
    {
        cout << "? " << x << " " << v.size() << " ";
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;

        int res;
        cin >> res;
        return res;
    };

    vector<int> tmp(n);
    for (int i = 0; i < n; i++)
        tmp[i] = i + 1;
    for (int i = 1; i <= n; i++)
    {
        auto res = query(i, tmp);
        a[res].push_back(i);
    }

    int siz;
    vector<int> ans;
    for (int len = n; len >= 1; len--)
    {
        if (a[len].size()) 
        {
            siz = len;
            ans.push_back(*a[len].begin());
            break;
        }
    }

    for (int len = siz - 1; len >= 1; len--)
    {
        for (auto v : a[len])
        {
            vector<int> tmp = {ans.back(), v};
            int res = query(ans.back(), tmp);
            if (res != 1)
            {
                ans.push_back(v);
                break;
            }
        }
    }

    cout << "! " << siz << " ";
    for (int i = 0; i < ans.size(); i++)
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
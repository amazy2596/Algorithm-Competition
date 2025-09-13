// Problem: F. Gravity Falls
// URL: https://codeforces.com/contest/2148/problem/F
// Author: amazy
// Date: 2025-09-13 23:16:28

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
    vector<deque<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        g[i].resize(k);
        for (int j = 0; j < k; j++)
            cin >> g[i][j];
    }

    vector<int> ans;
    while (true)
    {
        sort(g.begin(), g.end(), [&](deque<int> &a, deque<int> &b) {
            int m = min(a.size(), b.size());
            for (int i = 0; i < m; i++)
            {
                if (a[i] < b[i])
                    return false;
                else if (a[i] > b[i])
                    return true;
            } 

            if (m == a.size()) return false;
            return true;
        });

        int m = g.back().size();
        for (int j = 0; j < m; j++)
            ans.push_back(g.back()[j]);
        
        for (int i = 0; i < g.size(); i++)
            for (int j = 0; g[i].size() && j < m; j++)
                g[i].pop_front();

        while (g.size() && g.back().size() == 0)
            g.pop_back();

        if (g.size() == 0)
            break;
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
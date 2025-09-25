// Problem: C. Max Tree
// URL: https://codeforces.com/contest/2143/problem/C
// Author: amazy
// Date: 2025-09-25 10:31:48

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
    vector<vector<int>> adj(n + 1);
    vector<int> in(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        if (x > y)
        {
            adj[v].push_back(u);
            in[u]++;
        }
        else 
        {
            adj[u].push_back(v);
            in[v]++;
        }
    }

    vector<int> rank(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++) if (in[i] == 0)
        q.push(i);

    int cnt = 1;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        rank[u] = cnt++;

        for (auto v : adj[u])
        {
            if (--in[v] == 0)
            {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << rank[i] << " \n"[i == n];
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
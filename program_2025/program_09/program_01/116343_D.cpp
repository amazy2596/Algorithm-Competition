// Problem: 小红走迷宫
// URL: https://ac.nowcoder.com/acm/contest/116343/D
// Author: amazy
// Date: 2025-09-01 12:29:01

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
    int n, m, x;
    cin >> n >> m >> x;
    set<int> a;
    for (int i = 0; i < x; i++)
    {
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    set<int> s;
    q.push(1);
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        if (s.count(u) || a.count(u))
            continue;
        s.insert(u);

        for (auto v : adj[u])
        {
            if (s.count(v))
                continue;

            q.push(v);
        }
    }

    for (auto &o : s)
        cout << o << " \n"[o == *s.rbegin()];
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
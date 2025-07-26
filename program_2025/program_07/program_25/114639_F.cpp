#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> adj(n + 1);
    vector<int> tmp(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j++)
        {
            int b;
            cin >> b;
            adj[id].push_back(b);
            tmp[b]++;
        }
    }

    auto check = [&](int x)
    {
        auto cur = a;
        cur[1] -= x;
        queue<int> q;
        auto d = tmp;
        for (int i = 1; i <= n; i++)
        {
            if (d[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            // if (cur[u] < -inf)
                // return false;

            int add = max(0ll, -cur[u]);
            for (auto v : adj[u])
            {
                cur[v] -= add;
                if (--d[v] == 0 && adj[v].size() != 0)
                    q.push(v);
            }
            cur[u] += add;
        }

        for (int i = 1; i <= n; i++)
        {
            if (cur[i] < 0)
                return false;
        }

        return true;
    };

    int l = 0, r = 1e15 + 5;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) 
            l = mid;
        else 
            r = mid - 1;
    }

    cout << l << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
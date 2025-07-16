#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> d(n + 1);
    for (int u = 1; u <= n; u++)
    {
        int m;
        cin >> m;
        for (int id = 1; id <= m; id++)
        {
            int v;
            cin >> v;
            adj[u].push_back(v);
            d[v]++;
        }
    }

    vector<int> in_cycle(n + 1, 1);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            q.push(i);
            in_cycle[i] = 0;
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (--d[v] == 0)
            {
                in_cycle[v] = 0;
                q.push(v);                
            }
        }
    }

    
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
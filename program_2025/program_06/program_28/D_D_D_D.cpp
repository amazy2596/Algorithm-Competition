#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, m, len;
    cin >> n >> m >> len;
    int sum = 0, mn = inf;
    for (int i = 0; i < len; i++)
    {
        int x;
        cin >> x;
        sum += x;
        if (x % 2 == 1)
            mn = min(mn, x);
    }

    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<array<int, 2>> dists(n + 1, {inf, inf});
    queue<pair<int, int>> q;
    q.push({1, 0});
    dists[1][0] = 0;
    while (!q.empty())
    {
        auto [u, dist] = q.front();
        q.pop();

        int p = dist % 2;
        for (auto v : adj[u])
        {
            if (dists[v][p ^ 1] > dist + 1)
            {
                dists[v][p ^ 1] = dist + 1;
                q.push({v, dists[v][p ^ 1]});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        bool f = 0;
        for (int p : {0, 1})
        {
            if ((dists[i][p] <= sum && p == sum % 2) || (dists[i][p] <= sum - mn && p != sum % 2))
                f |= 1;
        }

        cout << f;
    }

    cout << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    vector<int> d(n + 1);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        d[u]++, d[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, int> circle;
    map<int, vector<int>> mp;
    queue<int> q;
    vector<int> temp_d = d;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 1)
            q.push(i);
        circle[i]++;
        if (d[i] >= 4)
            mp[d[i]].push_back(i);
    }
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        circle.erase(u);

        for (auto v : adj[u])
        {
            temp_d[v]--;
            if (temp_d[v] == 1)
                q.push(v);
        }
    }

    int ans = 0;
    map<pair<int, int>, int> vis;
    for (auto [u, _] : circle)
    {
        for (auto v : adj[u])
        {
            if (circle.find(v) != circle.end())
            {
                if (vis[{u, v}])
                    continue;
                vis[{u, v}]++;
                vis[{v, u}]++;
                if (mp[5].size() == 0)
                {
                    ans += n - mp[4].size();
                    if (d[u] == 4)
                        ans++;
                    if (d[v] == 4)
                        ans++;
                }
                else if (mp[5].size() == 1)
                {
                    auto &vec = mp[5];
                    auto tar = vec.back();

                    if (u == tar)
                    {
                        if (d[v] == 4)
                            ans += n - mp[4].size();
                        else 
                            ans += n - mp[4].size() - 1;
                    }
                    else if (v == tar)
                    {
                        if (d[u] == 4)
                            ans += n - mp[4].size();
                        else 
                            ans += n - mp[4].size() - 1;
                    }
                }
                else if (mp[5].size() == 2)
                {
                    if (d[u] == 5 && d[v] == 5)
                    {
                        ans += n - mp[4].size() - 2;
                    }
                }
            }
        }
    }

    cout << ans << "\n";
}

signed main()
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
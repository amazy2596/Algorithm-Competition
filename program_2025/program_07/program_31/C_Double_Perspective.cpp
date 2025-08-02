#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct DSU
{
    vector<int> f, siz;

    DSU(int n) : f(n + 1), siz(n + 1, 1)
    {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x)
    {
        while (f[x] != x)
            x = f[x] = f[f[x]];
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (siz[x] < siz[y])
            swap(x, y);

        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

struct node
{
    int u, v, id, len;
};

void solve()
{
    int n;
    cin >> n;
    int m = 2 * n;
    vector<pair<int, int>> a(n + 1);
    vector<vector<pair<int, int>>> adj(m + 1);
    vector<int> d(m + 1);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        a[i] = {u, v};
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        d[v]++;
        d[u]++;
    }

    queue<int> q;
    vector<int> not_in(m + 1);
    for (int i = 1; i <= m; i++)
    {
        if (d[i] == 1)
        {
            q.push(i);
            not_in[i] = 1;
        }
    }

    set<int> ans;
    int f = 0, g = 0;
    map<pair<int, int>, int> seg;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto [v, id] : adj[u])
        {
            ans.insert(id);
            int x = min(u, v), y = max(u, v);
            for (int i = x + 1; i <= y; i++)
                seg[{i - 1, i}]++;
            
            if (--d[v] == 1)
            {
                q.push(v);
                not_in[v] = 1;
            }
        }
    }
    f += seg.size();

    vector<int> vis(m + 1, 0);
    map<int, vector<int>> circle;
    int cnt = 0;
    for (int i = 1; i <= m; i++) 
    {
        if (!not_in[i] && !vis[i]) 
        { 
            cnt++;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            set<int> tmp;

            while(!q.empty())
            {
                int u = q.front();
                q.pop();

                for(auto [v, id] : adj[u])
                {
                    if(!not_in[v]){

                        tmp.insert(id);
                        if(!vis[v])
                        {
                            vis[v] = 1;
                            q.push(v);
                        }
                    }
                }
            }

            for(int id : tmp)
                circle[cnt].push_back(id);
        }
    }

    for (auto &[val, vec] : circle)
    {
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        if (vec.empty()) continue;

        set<int> nodes;
        vector<node> e;
        for (int id : vec) 
        {
            auto [u, v] = a[id];
            nodes.insert(u);
            nodes.insert(v);
            e.push_back({u, v, id, v - u});
        }
        
        map<pair<int,int>, int> temp_seg_A = seg;
        for (const auto& edge : e) 
        {
            for (int i = edge.u; i < edge.v; ++i) 
            {
                temp_seg_A[{i, i + 1}]++;
            }
        }
        int score_A = temp_seg_A.size() - seg.size() - nodes.size();

        sort(e.begin(), e.end(), [](node &e1, node &e2) {
            return e1.len > e2.len;
        });

        DSU dsu(m);
        vector<pair<int, int>> segs;
        vector<int> idx;

        for (const auto& edge : e) 
        {
            if (dsu.merge(edge.u, edge.v)) 
            {
                segs.push_back({edge.u, edge.v});
                idx.push_back(edge.id);
            }
        }
        
        map<pair<int, int>, int> temp_seg_B = seg;
        for (auto [u, v] : segs)
        {
            for (int i = u + 1; i <= v; i++)
            {
                temp_seg_B[{i - 1, i}]++;
            }
        }

        int score_B = temp_seg_B.size() - seg.size();

        if (score_A > score_B) 
        {
            for (int id : vec) 
            {
                ans.insert(id);
            }
        } else 
        {
            for (int id : idx) 
            {
                ans.insert(id);
            }
        }
    }

    // cout << f - g << "\n";
    cout << ans.size() << "\n";
    for (auto id : ans)
        cout << id << " ";
    cout << "\n";
}

signed main()
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
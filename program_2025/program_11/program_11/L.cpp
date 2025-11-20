// #include <bits/stdc++.h>
// using namespace std;
// using i64 = int64_t;
// using u64 = uint64_t;
// using f64 = long double;
// using i128 = __int128_t;
// using u128 = __uint128_t;

// const long double eps = 1e-12;
// const i64 mod = 1e9 + 7;
// const i64 INF = 1e18;
// const int inf = 1e9;

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

// struct HLD
// {
//     int n;
//     int id = 0;
//     vector<vector<int>> adj;

//     vector<int> fa;
//     vector<int> deep;
//     vector<int> siz;
//     vector<int> son;

//     vector<int> dfn;
//     vector<int> rev;
//     vector<int> top;

//     HLD(int _n) : n(_n)
//     {
//         adj.resize(n + 1);
//         fa.resize(n + 1, -1);
//         deep.resize(n + 1);
//         siz.resize(n + 1);
//         son.resize(n + 1);

//         dfn.resize(n + 1);
//         rev.resize(n + 1);
//         top.resize(n + 1); 
//     }

//     void build(int root = 1)
//     {
//         id = 0;
//         dfs1(root, -1, 0);
//         dfs2(root, root);
//     }

//     void add(int u, int v)
//     {
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     void dfs1(int u, int p, int d)
//     {
//         fa[u] = p;
//         deep[u] = d;
//         siz[u] = 1;
//         for (auto v : adj[u])
//         {
//             if (v == p)
//                 continue;
//             dfs1(v, u, d + 1);
//             if (siz[v] > siz[son[u]]) son[u] = v;
//             siz[u] += siz[v];
//         }
//     }

//     void dfs2(int u, int t)
//     {
//         top[u] = t;
//         dfn[u] = id++;
//         rev[dfn[u]] = u;
//         if (son[u]) dfs2(son[u], t);
//         for (auto v : adj[u])
//         {
//             if (v == fa[u] || v == son[u])
//                 continue;
//             dfs2(v, v);
//         }
//     }

//     int dist(int u, int v) 
//     {
//         return deep[u] + deep[v] - 2 * deep[lca(u, v)];
//     }

//     int lca(int u, int v) 
//     {
//         while (top[u] != top[v]) 
//         {
//             if (deep[top[u]] < deep[top[v]]) 
//                 swap(u, v);
//             u = fa[top[u]];
//         }
//         return deep[u] < deep[v] ? u : v;
//     }

//     int kth(int u, int k) 
//     {
//         if (k < 0) return -1;
//         if (deep[u] < k) return -1;
//         while (u != -1)
//         {
//             int d = dfn[u] - dfn[top[u]];
//             if (k <= d) return rev[dfn[u] - k];

//             k -= d + 1;
//             u = fa[top[u]];
//         }

//         return -1;
//     }

//     bool is_anc(int u, int v) 
//     {
//         return dfn[u] <= dfn[v] && dfn[v] < dfn[u] + siz[u];
//     }

//     vector<pair<int,int>> vtree(vector<int> nodes, int root = 1) 
//     {
//         auto cmp = [&](int x, int y) { return dfn[x] < dfn[y]; };
//         sort(nodes.begin(), nodes.end(), cmp);
//         nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

//         vector<int> all = nodes;
//         for (int i = 1; i < nodes.size(); i++) all.push_back(lca(nodes[i - 1], nodes[i]));
//         sort(all.begin(), all.end(), cmp);
//         all.erase(unique(all.begin(), all.end()), all.end());

//         vector<pair<int,int>> edges;
//         vector<int> st;
//         for (int v : all) 
//         {
//             if (st.empty()) 
//             { 
//                 st.push_back(v); 
//                 continue; 
//             }
//             while (!st.empty() && !is_anc(st.back(), v)) 
//                 st.pop_back();
//             edges.emplace_back(st.back(), v);
//             st.push_back(v);
//         }
//         return edges;
//     }
// };

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n + 1), b(n + 1);
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     for (int i = 1; i <= n; i++) cin >> b[i];

//     HLD hld(n + 1);
//     for (int i = 1; i <= n - 1; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         hld.add(u, v);
//     }
//     hld.build(1);
//     auto &adj = hld.adj;
//     auto &dfn = hld.dfn;
//     auto &rev = hld.rev;
//     auto &siz = hld.siz;
//     auto &son = hld.son;

//     string ans(n + 1, '0');
//     unordered_map<int, int> mpa, mpb;
//     int othera = 0, otherb = 0;
//     auto dfs = [&](auto dfs, int u, int p, int keep) -> void
//     {
//         for (auto v : adj[u])
//         {
//             if (v == p || v == son[u]) continue;
//             dfs(dfs, v, u, 0);
//         }

//         if (son[u]) dfs(dfs, son[u], u, 1);

//         for (auto v : adj[u])
//         {
//             if (v == p || v == son[u]) continue;
//             for (int idx = dfn[v]; idx < dfn[v] + siz[v]; idx++)
//             {
//                 int t = rev[idx];
//                 if (a[t] == 0) mpa[0]++;
//                 else 
//                 {
//                     if (mpb[a[t]]) mpb[a[t]]--, otherb--;
//                     else mpa[a[t]]++, othera++;
//                 }

//                 if (b[t] == 0) mpb[0]++;
//                 else 
//                 {
//                     if (mpa[b[t]]) mpa[b[t]]--, othera--;
//                     else mpb[b[t]]++, otherb++;
//                 }
//             }
//         }

//         if (a[u] == 0) mpa[0]++;
//         else 
//         {
//             if (mpb[a[u]]) mpb[a[u]]--, otherb--;
//             else mpa[a[u]]++, othera++;
//         }

//         if (b[u] == 0) mpb[0]++;
//         else 
//         {
//             if (mpa[b[u]]) mpa[b[u]]--, othera--;
//             else mpb[b[u]]++, otherb++;
//         }

//         if (mpa[0] >= otherb && mpb[0] >= othera) ans[u] = '1';

//         if (keep == 0)
//         {
//             for (int idx = dfn[u]; idx < dfn[u] + siz[u]; idx++)
//             {
//                 int t = rev[idx];
//                 mpa[a[t]] = 0;
//                 mpb[b[t]] = 0;
//             }
//             othera = otherb = 0;
//         }
//     };

//     dfs(dfs, 1, 0, 0);

//     cout << ans.substr(1) << "\n";
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(nullptr);
//     cin.tie(nullptr);
//     int T = 1;
//     cin >> T;
//     while (T--)
//         solve();
//     return 0;
// }

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

struct HLD
{
    int n;
    int id = 0;
    vector<vector<int>> adj;

    vector<int> fa;
    vector<int> deep;
    vector<int> siz;
    vector<int> son;

    vector<int> dfn;
    vector<int> rev;
    vector<int> top;

    HLD(int _n) : n(_n)
    {
        adj.resize(n + 1);
        fa.resize(n + 1, -1);
        deep.resize(n + 1);
        siz.resize(n + 1);
        son.resize(n + 1);

        dfn.resize(n + 1);
        rev.resize(n + 1);
        top.resize(n + 1); 
    }

    void build(int root = 1)
    {
        id = 0;
        dfs1(root, -1, 0);
        dfs2(root, root);
    }

    void add(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs1(int u, int p, int d)
    {
        fa[u] = p;
        deep[u] = d;
        siz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs1(v, u, d + 1);
            if (siz[v] > siz[son[u]]) son[u] = v;
            siz[u] += siz[v];
        }
    }

    void dfs2(int u, int t)
    {
        top[u] = t;
        dfn[u] = id++;
        rev[dfn[u]] = u;
        if (son[u]) dfs2(son[u], t);
        for (auto v : adj[u])
        {
            if (v == fa[u] || v == son[u])
                continue;
            dfs2(v, v);
        }
    }

    int dist(int u, int v) 
    {
        return deep[u] + deep[v] - 2 * deep[lca(u, v)];
    }

    int lca(int u, int v) 
    {
        while (top[u] != top[v]) 
        {
            if (deep[top[u]] < deep[top[v]]) 
                swap(u, v);
            u = fa[top[u]];
        }
        return deep[u] < deep[v] ? u : v;
    }

    int kth(int u, int k) 
    {
        if (k < 0) return -1;
        if (deep[u] < k) return -1;
        while (u != -1)
        {
            int d = dfn[u] - dfn[top[u]];
            if (k <= d) return rev[dfn[u] - k];

            k -= d + 1;
            u = fa[top[u]];
        }

        return -1;
    }

    bool is_anc(int u, int v) 
    {
        return dfn[u] <= dfn[v] && dfn[v] < dfn[u] + siz[u];
    }

    vector<pair<int,int>> vtree(vector<int> nodes, int root = 1) 
    {
        auto cmp = [&](int x, int y) { return dfn[x] < dfn[y]; };
        sort(nodes.begin(), nodes.end(), cmp);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

        vector<int> all = nodes;
        for (int i = 1; i < nodes.size(); i++) all.push_back(lca(nodes[i - 1], nodes[i]));
        sort(all.begin(), all.end(), cmp);
        all.erase(unique(all.begin(), all.end()), all.end());

        vector<pair<int,int>> edges;
        vector<int> st;
        for (int v : all) 
        {
            if (st.empty()) 
            { 
                st.push_back(v); 
                continue; 
            }
            while (!st.empty() && !is_anc(st.back(), v)) 
                st.pop_back();
            edges.emplace_back(st.back(), v);
            st.push_back(v);
        }
        return edges;
    }
};

struct query
{
    int l, r, id, blk_id;

    bool operator<(const query &o)
    {
        if (blk_id != o.blk_id) return blk_id < o.blk_id;

        if (blk_id & 1) return r < o.r;
        return r > o.r;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    HLD hld(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        hld.add(u, v);
    }
    hld.build(1);

    auto &adj = hld.adj;
    auto &dfn = hld.dfn;
    auto &siz = hld.siz;
    auto &rev = hld.rev;

    vector<query> qs;
    int B = max(1, (int)sqrt(n));
    for (int i = 1; i <= n; i++) qs.push_back({dfn[i], dfn[i] + siz[i] - 1, i, dfn[i] / B});
    sort(qs.begin(), qs.end());

    vector<int> diff(n + 1);
    int needa = 0, needb = 0;
    int x = 0, y = 0;

    auto update = [&](int x, int delta)
    {
        int old = diff[x];
        if (old > 0) needa -= old;
        else if (old < 0) needb -= old;
        int now = old + delta;
        diff[x] = now;
        if (now > 0) needa += now;
        else if (now < 0) needb += now;
    };

    auto add = [&](int pos)
    {
        int u = rev[pos];
        if (a[u] == 0) x++;
        else update(a[u], -1);
        if (b[u] == 0) y++;
        else update(b[u], 1);
    };

    auto remove = [&](int pos)
    {
        int u = rev[pos];
        if (a[u] == 0) x--;
        else update(a[u], 1);
        if (b[u] == 0) y--;
        else update(b[u], -1);
    };

    string ans(n + 1, '0');
    int l = 1, r = 0;
    for (auto q : qs)
    {
        while (l > q.l) add(--l);
        while (r < q.r) add(++r);
        while (l < q.l) remove(l++);
        while (r > q.r) remove(r--);

        if (x >= needa && y >= needb) ans[q.id] = '1';
    }

    cout << ans.substr(1) << "\n";
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
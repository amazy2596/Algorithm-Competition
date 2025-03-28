// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// const int N = 2e5 + 5;

// vector<int> a, depth;
// vector<vector<int>> adj;
// int maxDepth = 0, n;

// void dfs(int node, int p, int d)
// {
//     depth[node] = d;
//     maxDepth = max(maxDepth, d);

//     for (int neighbor : adj[node])
//     {
//         if (neighbor != p)
//             dfs(neighbor, node, d + 1);
//     }
// }

// int mn = 1e9;

// void traverse_by_depth(int curDepth)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         if (depth[i] == curDepth)
//         {
//             int cur_mn = 1e9;
//             bool f = 0;
//             for (int child : adj[i])
//             {
//                 if (depth[child] == curDepth + 1)
//                 {
//                     cur_mn = min(cur_mn, a[child]);
//                     f = 1;
//                 }
//             }
//             if (curDepth == 0)
//             {
//                 a[i] += cur_mn;
//                 break;
//             }
//             else 
//             {
//                 if (f)
//                 {
//                     if (cur_mn > a[i])
//                     {
//                         a[i] = (a[i] + cur_mn) / 2;
//                         mn = min(mn, a[i]);
//                     }
//                     else
//                         mn = min(mn, cur_mn);
//                 }
//             }
//         }
//     }
// }

// void solve()
// {
//     cin >> n;
//     adj.clear();
//     adj.resize(n + 1);
//     depth.clear();
//     depth.resize(n + 1, 0);
//     a.clear();
//     a.resize(n + 1, 0);
//     mn = 1e9;
//     maxDepth = 0;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     for (int y = 2; y <= n; y++)
//     {
//         int x;
//         cin >> x;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
//     dfs(1, -1, 0);
//     for (int d = maxDepth - 1; d >= 0; d--)
//         traverse_by_depth(d);
    
//     cout << a[1] << "\n";
// }

// signed main()
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
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> tree(n + 1);
    for (int y = 2; y <= n; y++)
    {
        int x;
        cin >> x;
        tree[x].push_back(y);
    }
    auto check = [&](auto self, int v, int mid)
    {
        if (mid >= INT32_MAX)
            return false;
        if (v != 1)
            mid += max(0ll, mid - a[v]);
        bool isLeaf = true;
        for (auto u : tree[v])
        {
            isLeaf = false;
            if (!self(self, u, mid))
                return false;
        }

        return (!isLeaf || mid <= a[v]);
    };

    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(check, 1, mid))
            l = mid;
        else 
            r = mid - 1;
    }

    cout << a[1] + l << "\n";
}

signed main()
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
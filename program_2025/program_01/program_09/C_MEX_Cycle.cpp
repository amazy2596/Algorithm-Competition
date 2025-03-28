#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> adj(n + 1);
    adj[x].push_back(y);
    adj[y].push_back(x);
    for (int i = 1; i <= n; i++)
    {
        int a = i - 1, b = i + 1;
        if (a == 0)
            a = n;
        if (b == n + 1)
            b = 1;
        adj[i].push_back(a);
        adj[i].push_back(b);
    }
    vector<int> ans(n + 1);
    for (auto v : adj[1])
        ans[v]++;
    int num = 10;
    while (num--)
    {
        for (int i = 2; i <= n; i++)
        {
            bool a = 0, b = 0, c = 0;
            for (auto v : adj[i])
            {
                if (ans[v] == 0)
                    a = 1;
                if (ans[v] == 1)
                    b = 1;
                if (ans[v] == 2)
                    c = 1;
            }
            if (a && b && c)
                ans[i] = 3;
            else if (a && b && !c)
                ans[i] = 2;
            else if (a && !b)
                ans[i] = 1;
            else if (!a)
                ans[i] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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
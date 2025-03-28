#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }
    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> f(n + 1), vis(n + 1);
    function<void(int)> dfs = [&](int u)
    {
        int sum = 0, child = 0;
        vis[u] = true;
        for (int v : a[u])
        {
            if (vis[v])
                continue;
            dfs(v);
            child++;
            sum += f[v];
        }

        if (child == 0)
        {
            f[u] = 1;
            f[u] %= mod;
        }
        else 
        {
            f[u] = 1 + sum * fast_pow(child, mod - 2);
            f[u] %= mod;
        }
    };
    dfs(1);
    cout << f[1] % mod << '\n';
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
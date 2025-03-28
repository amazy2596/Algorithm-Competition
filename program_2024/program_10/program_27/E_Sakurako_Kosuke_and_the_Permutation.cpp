#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> vis;
vector<int> a;
int dfs(int x)
{
    if (vis[x])
        return 0;
    vis[x] = 1;
    return dfs(a[x]) + 1;
}


void solve()
{
    cin >> n;
    vis.resize(n + 1, 0);
    vis.assign(n + 1, 0);
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = dfs(i);
        if (cnt > 2)
            ans += (cnt - 1) / 2;
    }
    cout << ans << "\n";
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
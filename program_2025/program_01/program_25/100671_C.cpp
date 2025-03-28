#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> g[i], g[i] = " " + g[i];
    
    map<string, int> mp;

    for (int j = 1; j <= m; j++)
    {
        string s = "";
        for (int i = 1; i <= n; i++)
            s += g[i][j];
        
        mp[s]++;
    }

    int ans = 0;
    for (auto [_, val] : mp)
        ans = max(ans, val);
    
    cout << ans;
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
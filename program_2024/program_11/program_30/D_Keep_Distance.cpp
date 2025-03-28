#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans;
    vector<int> cur;
    auto dfs = [&](auto dfs, int last) -> void
    {
        if (cur.size() == n)
        {
            ans.push_back(cur);
            return;
        }
        for (int i = last; i + (n - cur.size() - 1) * 10 <= m; i++)
        {
            if (i <= m)
            {
                cur.push_back(i);
                dfs(dfs, i + 10);
                cur.pop_back();
            }
        }
    };
    dfs(dfs, 1);
    cout << ans.size() << "\n";
    for (auto a : ans)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];
    }
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
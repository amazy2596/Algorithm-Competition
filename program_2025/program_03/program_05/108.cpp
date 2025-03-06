#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    vector<int> ans;
    auto dfs1 = [&](auto dfs1, int l, int r) -> bool
    {
        if (l > r)
            return true;
        if (l == r)
        {
            ans.push_back(a[l]);
            return true;
        }
        int idx = -1;
        for (int i = l + 1; i <= r; i++)
        {
            if (idx != -1)
            {
                if (a[i] < a[l])
                    return false;
                continue;
            }
            if (a[i] >= a[l])
                idx = i;
        }

        if (idx == -1)
            idx = r + 1;

        if (dfs1(dfs1, l + 1, idx - 1) && dfs1(dfs1, idx, r))
        {
            ans.push_back(a[l]);
            return true;
        }

        return false;
    };

    if (dfs1(dfs1, 1, n))
    {
        cout << "YES\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    else 
    {
        ans.clear();
        auto dfs2 = [&](auto dfs2, int l, int r) -> bool
        {
            if (l > r)
                return true;
            if (l == r)
            {
                ans.push_back(a[l]);
                return true;
            }

            int idx = -1;
            for (int i = l + 1; i <= r; i++)
            {
                if (idx != -1)
                {
                    if (a[i] > a[l])
                        return false;
                    continue;
                }
                if (a[i] < a[l])
                    idx = i;
            }
            if (idx == -1)
                idx = r + 1;
            
            if (dfs2(dfs2, l + 1, idx - 1) && dfs2(dfs2, idx, r))
            {
                ans.push_back(a[l]);
                return true;
            }
            return false;
        };

        if (dfs2(dfs2, 1, n))
        {
            cout << "YES\n";
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " \n"[i == ans.size() - 1];
        }
        else 
            cout << "NO\n";
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
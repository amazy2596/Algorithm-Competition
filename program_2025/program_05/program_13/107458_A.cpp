#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<char> cand = {'A', 'B', 'C', 'D'};

    vector<int> idx, vis(4);
    auto dfs = [&](auto dfs) -> void
    {
        if (idx.size() == n)
        {
            for (int i = 0; i < idx.size(); i++)
                cout << cand[idx[i]] << "+ "[i == idx.size() - 1];
            cout << "Problem\n";
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            vis[i] = 1;
            idx.push_back(i);
            dfs(dfs);
            vis[i] = 0;
            idx.pop_back();
        }
    };

    dfs(dfs);
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
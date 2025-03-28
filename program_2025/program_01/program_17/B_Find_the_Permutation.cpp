#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<map<int, int>> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '1')
                adj[i][j + 1]++;
        }
    }

    vector<int> ans;
    ans.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        bool f = 1;
        for (int j = 0; j < ans.size(); j++)
        {
            if (adj[i].find(ans[j]) == adj[i].end())
            {
                ans.insert(ans.begin() + j, i);
                f = 0;
                break;
            }
        }
        if (f)
            ans.push_back(i);
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
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
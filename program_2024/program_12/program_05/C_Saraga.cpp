#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    s = ' ' + s;
    t = ' ' + t;
    vector<vector<int>> idx(26);
    for (int i = m - 1; i >= 1; i--)
        idx[(t[i] - 'a')].push_back(i);
    string ans = "-1";
    for (int i = 2; i <= n; i++)
    {
        int tar = s[i] - 'a';
        int j = -1;
        if (idx[tar].size())
            j = *idx[tar].begin();
        if (j == -1)
            continue;
        int len = i + m - j;
        if (ans == "-1" || len < ans.length())
            ans = s.substr(1, i) + t.substr(j + 1);
    }
    cout << ans << "\n";
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
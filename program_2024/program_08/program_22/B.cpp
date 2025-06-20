#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.length();
    vector<int> l(n + 1, 1), r(n + 1, 1);
    for (int i = 0; i < n; i++)
        l[i + 1] = l[i] && (s[i] == t[i]);
    for (int i = n; i > 0; i--)
        r[i - 1] = r[i] && (s[i - 1] == t[i]);
    vector<pair<int, char>> ans;
    for (int i = 0; i <= n; i++)
    {
        if (l[i] && r[i])
            ans.push_back({i, t[i]});
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
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
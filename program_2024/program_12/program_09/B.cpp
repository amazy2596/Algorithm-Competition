#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 2)
    {
        if (s[0] == s[1])
            cout << 0 << "\n";
        else
            cout << "-1\n";
        return;
    }
    vector<vector<int>> last(26);
    int ans = 1e9;
    for (int i = 0; i < s.length(); i++)
    {
        if (last[s[i] - 'a'].size())
        {
            for (int j = 0; j < last[s[i] - 'a'].size(); j++)
            {
                int dist = min(i - last[s[i] - 'a'][j] - 1, (n - 1 - i) + last[s[i] - 'a'][j]);
                ans = min(ans, dist);
            }
        }
        last[s[i] - 'a'].push_back(i);
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";
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
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vector<int> found(k, 0);
    string ans = "";
    int count = 0;
    for (auto c : s)
    {
        if (ans.length() == n)
            break;
        count += !found[c - 'a'];
        found[c - 'a'] = 1;
        if (count == k)
        {
            found.assign(k, 0);
            ans.push_back(c);
            count = 0;
        }
    }
    if (ans.length() == n)
        cout << "YES\n";
    else
    {
        int idx = 0;
        for (int i = 0; i < found.size(); i++)
        {
            if (found[i] == 0)
            {
                idx = i;
                break;
            }
        }
        while (ans.length() < n)
            ans.push_back('a' + idx);
        cout << "NO\n";
        cout << ans << "\n";
    }
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
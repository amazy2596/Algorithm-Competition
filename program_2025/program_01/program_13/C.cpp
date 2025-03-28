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

    if (s.back() == '0')
    {
        cout << -1;
        return;
    }

    vector<int> ans;
    int last = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            for (int j = i + 1; j > last; j--)
                ans.push_back(j);
            last = i + 1;
        }
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
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
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
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            cur++;
        else 
        {
            ans += cur / 2;
            cur = 0;
        }
    }

    if (cur)
        ans += cur / 2;

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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    if (s.find_last_not_of('0') == -1)
    {
        int ans = 0;
        for (int i = 0; i < s.length() - 1; i++)
            ans += (s[i] != '0');

        cout << ans << "\n";
    }
    else 
    {
        int idx = s.find_last_not_of('0');
        int ans = s.length() - idx - 1;
        for (int i = 0; i < idx; i++)
            ans += (s[i] != '0');

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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string tar = "while";
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
        ans += s[i] != tar[i];

    cout << ans;
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
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
        ans += s[i] == '.';
    ans += min(n - ans, d);
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
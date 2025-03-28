#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    int ans = 0;
    int i = 0, j = 0;
    while (i < s.length() && j < t.length() && s[i++] == t[j++])
        ans++;
    cout << s.length() + t.length() - ans + (s[0] == t[0]) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
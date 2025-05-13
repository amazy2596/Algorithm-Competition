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

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += s[i] == '5';

    int ans = 0;
    for (int i = 0; i < cnt; i++)
        ans += s[i] != '5';
        
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
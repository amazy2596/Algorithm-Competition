#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0, sum = 0;
    bool f = 1;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (f && sum + s.length() <= m)
            sum += s.length(), ans++;
        else 
            f = 0;
    }
    cout << ans << "\n";
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
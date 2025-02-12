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
    int ans = 0, v = 0, last = 0;
    for (int i = 0; i < n; i++)
    {
        v += last;
        if (s[i] == '0')
            v += 10, last = 0;
        if (s[i] == '1')
            v = max(0ll, v - 5), last = 0;
        if (s[i] == '2')
            last = min(10ll, v), v = max(0ll, v - 10);
        ans += v;
    }

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
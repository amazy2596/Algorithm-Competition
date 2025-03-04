#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    s = " " + s;
    int ans = 0;
    vector<int> pre(n + 1);
    int cnt = -1;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + (s[i] == 'R' ? 1 : -1);
        if (cnt == -1 && pre[i] == 0)
            cnt = i;
        if (ans == 0 && pre[i] + x == 0)
        {
            k -= i;
            ans++;
        }
    }

    if (cnt == -1 || ans == 0)
    {
        cout << ans << "\n";
        return;
    }

    cout << ans + k / cnt << "\n";
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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<int> pre(n + 1);
    bool f1 = 1, f2 = 1;
    int idx1 = -1, idx2 = -1;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + (s[i] == '1' ? 1 : -1);
        if (pre[i] <= -3)
        {
            cout << "0\n";
            return;
        }
        if (f1 && pre[i] == -1)
            f1 = 0, idx1 = i;
        if (f2 && pre[i] == -2)
            f2 = 0, idx2 = i;
    }
    if (!f2)
    {
        int ans = 0;
        for (int i = 1; i < idx2; i++)
            ans += s[i] == '0';
        cout << ans << "\n";
        return;
    }
    if (!f1)
    {
        int ans = 0;
        for (int i = 1; i <= idx1; i++)
            ans += s[i] == '0';
        cout << ans << "\n";
        return;
    }

    cout << n << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
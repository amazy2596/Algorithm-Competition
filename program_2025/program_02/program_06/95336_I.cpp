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
    string tar = "uwawauwa";
    int ans = 0;
    vector<int> cnt1(n), cnt2(n), pre(n), suf(n);
    for (int i = 0; i < s.length() - 7; i++)
    {
        // cout << s.substr(i, 8) << "\n";
        if (s.substr(i, 8) == tar)
            cnt2[i] = 1;
        if (s[i] == 'u')
            cnt1[i] = 1;
        // pre[i] = (i == 0 ? 0 : pre[i - 1]) + cnt1[i];
    }

    for (int i = n - 1; i >= 0; i--)
        suf[i] = (i == n - 1 ? 0 : suf[i + 1]) + cnt2[i];

    for (int i = 0; i < s.length() - 7; i++)
    {
        if (cnt1[i] == 1)
            ans += suf[i + 2];
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
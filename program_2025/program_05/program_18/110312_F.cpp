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
    s = " " + s;
    vector<int> pre(n + 5), suf(n + 5);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (s[i] == '(');
    for (int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + (s[i] == ')');

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += (s[i] == ')');

    int ans = 1e9;
    for (int i = 1; i <= n; i++)
        ans = min(ans, pre[i - 1] + suf[i]);

    cout << min({ans, cnt, n - cnt}) << "\n";
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
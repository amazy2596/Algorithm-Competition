#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int mx = 0;
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mx = max(mx, x);
        q.push(x);
    }
    if (k == 1)
    {
        cout << mx << "\n";
        return;
    }
    int ans = 1e12, cnt = 0;
    while (!q.empty())
    {
        int top = q.top();
        q.pop();
        ans = min(ans, top + cnt);
        cnt++;
        top /= k;
        if (top != 0)
            q.push(top);
    }
    ans = min(ans, cnt);
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
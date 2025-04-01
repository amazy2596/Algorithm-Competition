#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> d(n + 1);
    priority_queue<int> q;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        q.push(d[i]);
        if ((n - i + 1) % (k + 1) == 0)
        {
            ans += q.top();
            q.pop();
        }
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
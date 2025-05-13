#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> r(n), c(m);
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        cin >> r[i], q.push({r[i], 0});
    for (int i = 0; i < m; i++)
        cin >> c[i], q.push({c[i], 1});

    int ans = 0;
    vector<pair<int, int>> row(n), col(m);
    while (!q.empty())
    {
        auto [val, f] = q.top();
        q.pop();

        if (f == 0)
            ans += val * m, n--;
        else 
            ans += val * n, m--;
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
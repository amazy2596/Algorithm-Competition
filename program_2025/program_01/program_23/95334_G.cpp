#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = 1, dis = abs(n - m), cnt = m;
    while (true)
    {
        int cur = cnt * m;
        if (abs(n - cur) < dis)
        {
            ans++;
            dis = abs(n - cur);
            cnt = cur;
        }
        else 
            break;
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
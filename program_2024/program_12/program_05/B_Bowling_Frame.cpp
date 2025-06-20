#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int w, b;
    cin >> w >> b;
    int ans = 1;
    while (true)
    {
        if (((1 + ans) * ans) / 2 > w + b)
            break;
        ans++;
    }
    cout << ans - 1 << "\n";
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
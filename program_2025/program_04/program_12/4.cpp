#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int ans = 0;
    while (true)
    {
        int op;
        cin >> op;
        if (op == 1)
            ans++;
        else if (op == 0)
            cout << ans << "\n";
        else 
            break;
    }
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
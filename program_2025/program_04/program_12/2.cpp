#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int w;
    cin >> w;
    if (w > 100)
        w = 100;
    else 
    {
        if (w % 10 == 0)
            w -= 10;
        else
            w = w / 10 * 10;
    }

    cout << "Gong xi nin! Nin de ti zhong yue wei: " << max(0ll, w) << " duo jin\n";
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
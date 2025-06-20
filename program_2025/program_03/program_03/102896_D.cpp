#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int t;
    cin >> t;

    auto calc = [&](int x)
    {
        return (2 * x + 1) * (2 * x + 1);
    };

    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (calc(mid) > t)
            r = mid - 1;
        else 
            l = mid;
    }

    t -= calc(l);
    int x = l, y = l;
    int cnt = 2 * (l + 1);

    if (t == 0)
    {
        cout << x << " " << y << "\n";
        return;
    }

    if (t >= cnt)
        x++, y -= cnt - 1, t -= cnt;
    else 
    {
        if (t == 1)
            x++, t--;
        else 
        {
            x++, y -= t - 1, t = 0;
            cout << x << " " << y << "\n";
            return;
        }
    }
    
    if (t >= cnt)
        x -= cnt, t -= cnt;
    else 
    {
        x -= t;
        cout << x << " " << y << "\n";
        return;
    }
    
    if (t >= cnt)
        y += cnt, t -= cnt;
    else 
    {
        y += t;
        cout << x << " " << y << "\n";
        return;
    }

    if (t >= cnt)
        x += cnt, t -= cnt;
    else 
    {
        x += t;
        cout << x << " " << y << "\n";
        return;
    }
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
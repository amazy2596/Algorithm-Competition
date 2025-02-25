#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;

    auto get = [&](int x)
    {
        if (x == 1)
            return 1ll;
        return (x * (x - 1) / 2);
    };
    
    int low1 = 1, high1 = 1ll << 30;
    while (low1 < high1)
    {
        int mid = low1 + high1 >> 1;
        if (get(mid) >= l)
            high1 = mid;
        else 
            low1 = mid + 1;
    }

    int low2 = 1, high2 = 1ll << 30;
    while (low2 < high2)
    {
        int mid = low2 + high2 >> 1;
        if (get(mid) >= r)
            high2 = mid;
        else 
            low2 = mid + 1;
    }

    if (low2 - low1 > 1)
        cout << "No\n";
    else if (low1 == low2)
        cout << "Yes\n";
    else 
    {
        if (l > r - low1 + 1)
            cout << "Yes\n";
        else 
            cout << "No\n";
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
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 > l2)
        swap(l1, l2), swap(r1, r2);
    int l = max(l1, l2), r = min(r1, r2);
    if (l2 > r1)
    {
        cout << 1 << "\n";
        return;
    }
    if (l1 == l2)
    {
        if (r1 == r2)
            cout << r - l << "\n";
        else 
            cout << r - l + 1 << "\n";
    }
    else if (l1 < l2)
    {
        if (r1 == r2)
            cout << r - l + 1 << "\n";
        else 
            cout << r - l + 2 << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
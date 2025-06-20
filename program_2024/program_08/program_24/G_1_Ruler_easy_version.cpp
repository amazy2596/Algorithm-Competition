#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l = 2, r = 1000;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        cout << "? 1 " << mid << endl;
        int mul;
        cin >> mul;
        if (mul == mid)
            l = mid + 1;
        else 
            r = mid;
    }
    cout << "! " << l << endl;
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
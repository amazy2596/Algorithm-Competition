#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int k;
    cin >> k;
    int l = 2, r = INT64_MAX;
    while (l < r)
    {
        int mid = (r - l) / 2 + l;
        int off = sqrtl(mid);
        if (mid - off >= k)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << "\n";
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
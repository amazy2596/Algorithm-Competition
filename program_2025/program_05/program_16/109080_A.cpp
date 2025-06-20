#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    vector<int> a(4);
    int x;
    cin >> a[1] >> a[2] >> a[3];
    cin >> x;
    for (int i = 1; i <= 3; i++)
    {
        if (i == x)
            continue;
        if (a[i] > a[x])
        {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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
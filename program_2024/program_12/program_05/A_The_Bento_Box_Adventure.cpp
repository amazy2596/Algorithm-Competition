#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    vector<int> a(6);
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= 5; i++)
    {
        if (a[i] == 0)
            cout << i << "\n";
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
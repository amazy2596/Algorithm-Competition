#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    for (int i = 1; i <= 5; i++)
    {
        int x; 
        cin >> x;
        if (x)
        {
            cout << i << "\n";
            return;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == 1)
    {
        if (k == 2)
            cout << "1 1";
        else 
            cout << "-1\n";
    }
    else if (k == 0)
    {
        if (n == 2)
        {
            cout << "-1";
            return;
        }
        for (int i = 1; i <= n; i++)
            cout << i << " " << i << " ";
    }
    else if (k == 1)
    {
        cout << "1 1 ";
        for (int i = 2; i <= n; i++)
            cout << i << " ";
        for (int i = 2; i <= n; i++)
            cout << i << " ";
    }
    else 
    {
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        k -= 2;
        for (int i = 1; i <= k; i++)
            cout << i << " ";
        for (int i = n; i > k; i--)
            cout << i << " ";
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
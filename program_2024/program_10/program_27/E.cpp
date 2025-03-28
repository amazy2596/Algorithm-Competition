#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], b[i] = a[i];
    int mx = 0, mn = 0;
    if (a[0] == -999)
        a[0] = 50;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == -999)
        {
            if (a[i - 1] - x >= -50)
            {
                a[i] = a[i - 1] - x;
                mx++;
            }
            else
                a[i] = 50;
        }
        else
            mx += (a[i - 1] - a[i] >= x);
    }
    bool f = 0;
    int j = 0;
    while (b[j] == -999 && j < n)
        j++;
    for (int i = j + 1; i < n; i++)
    {
        if (b[i] == -999)
        {
            if (b[i - 1] - x >= -50)
                b[i] = b[i - 1] - x + 1;
            else    
                b[i] = -50;
        }
        else
            mn += (b[i - 1] - b[i] >= x);
    }
    cout << mx << " " << mn;
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
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n - 1; i++)
        cin >> b[i];
    a[0] = b[0];
    a[1] = b[0];
    bool f = 1;
    for (int i = 2; i < n && f; i++)\
    {
        for (int k = 0; k < 30; k++)
        {
            if ((b[i - 1] >> k & 1) == 1)
            {
                a[i] += 1 << k;
                if ((a[i - 1] >> k & 1) == 0)
                    a[i - 1] += 1 << k;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i] & a[i + 1]) != b[i])
        {
            f = 0;
            break;
        }
    }
    if (f)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];
    }
    else 
        cout << "-1\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int x = a[i], y = a[x];
        if (x == y)
            continue;
        else
        {
            if (abs(x - y) == 1 && abs(i - x) == 1)
                swap(a[i], a[x]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != i)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
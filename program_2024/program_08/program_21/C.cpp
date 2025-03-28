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
    sort(a.begin() + 1, a.end());
    bool f = 1;
    for (int i = 2; i <= n - 1; i++)
    {
        if (a[i - 1] * a[i] >= a[i] * a[i + 1])
        {
            f = 0;
            break;
        }
    }
    if (f)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
    }
    else
        cout << "NO\n";
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
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k > n)
    {
        cout << "NO\n";
        return;
    }
    else if (k == n)
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << 0 << " ";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n - (k + 1); i++)
        cout << 0 << " ";
    for (int i = 0; i < k + 1; i++)
        cout << i % 2 << " ";
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
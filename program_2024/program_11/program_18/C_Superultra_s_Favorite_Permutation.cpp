#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n <= 4)
        cout << -1 << "\n";
    else if (n == 5)
        cout << "1 3 5 4 2\n";
    else if (n == 6)
        cout << "1 3 5 4 2 6\n";
    else if (n == 7)
        cout << "1 3 7 5 4 2 6\n";
    else
    {
        for (int i = 3; i <= n; i += 2)
            cout << i << " ";
        cout << "1 8 ";
        for (int i = 2; i <= n; i += 2)
        {
            if (i == 8)
                continue;
            cout << i << " ";
        }
    }
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
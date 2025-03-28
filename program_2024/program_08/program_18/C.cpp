#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a;
    cin >> a;
    for (int b = 1; b <= 1e9; b++)
    {
        int c = a ^ b;
        if (c >= 1 && c <= 1e9)
        {
            cout << b << " " << c << "\n";
            break;
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
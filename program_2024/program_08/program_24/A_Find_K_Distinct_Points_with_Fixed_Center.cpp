#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    int a = 0, b = 0;
    for (int i = 0; i < k - 1; i++)
    {
        cout << i - 500 << " " << i - 500 << "\n";
        a += i - 500, b += i - 500;
    }
    cout << k * x - a << " " << k * y - b << "\n";
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
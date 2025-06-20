#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    for (int i = 0; i < k; i++)
    {
        int x = (b + c) / 2;
        int y = (a + c) / 2;
        int z = (a + b) / 2;

        a = x, b = y, c = z;
        if (a == b && b == c)
            break;
    }

    cout << a << " " << b << " " << c << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
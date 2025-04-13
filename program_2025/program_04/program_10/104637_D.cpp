#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;

    if (x == y || (x & y) == 0)
    {
        cout << "1\n";
        return;
    }

    vector<int> t;
    t.push_back(x & y);
    t.push_back(x | y);
    t.push_back(x ^ y);
    t.push_back(__gcd(x, y));

    for (int z : t)
    {
        if ((x & z) == 0 || (y & z) == 0 || (x ^ z) == 0 || (y ^ z) == 0)
        {
            cout << "2\n";
            return;
        }
    }

    cout << "3\n";

    // for (int x = 1; x <= 100; x++)
    // {
        // for (int y = x; y <= 100; y++)
        // {
            // int a = x & y, b = x ^ y;
            // cout << (a & b) << "\n";
        // }
    // }
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
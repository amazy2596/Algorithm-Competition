#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    cout << 3 << "\n";
    for (int i = -1e6; i <= b; i++)
    {
        int j = 3 * a - b - i;
        if (1e6 >= j && j >= b && (i + j + b) / 3 == a)
        {
            cout << i << " " << b << " " << j << "\n";
            return;
        }
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
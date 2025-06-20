#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int k;
    cin >> k;
    k++;
    for (int i = 1; i <= sqrt(k); i++)
    {
        if (k % i == 0)
        {
            int j = k / i;
            int p = i + j - 2;
            int q = (i - 1) * (j - 1);
            if (p && q)
            {
                cout << p << " " << q;
                return;
            }
        }
    }

    cout << "-1\n";
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
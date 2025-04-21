#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    // x y
    // 0 0 -> 全0
    // 0 1 -> 无解  
    // 1 0 -> 偶数个1, 其他全0; n == 1, 无解;
    // 1 1 -> 奇数个1, 其他全0;

    int skip = 0;
    vector<int> a(n);
    for (int k = 0; k <= 31; k++)
    {
        int bitX = (x >> k) & 1, bitY = (y >> k) & 1;
        if (bitX == 0 && bitY == 1)
        {
            cout << "NO\n";
            return;
        }
        else if (bitX == 1 && bitY == 0)
        {
            if (n == 1)
            {
                cout << "NO\n";
                return;
            }
            
            if (n % 2 == 0)
            {
                for (int i = 0; i < n; i++)
                    a[i] |= (1ll << k);
            }
            else 
            {
                for (int i = 0; i < n; i++)
                {
                    if (i == skip)
                        continue;
                    a[i] |= (1ll << k);
                }
                skip = min(skip + 1, n - 1);
            }
        }
        else if (bitX == 1 && bitY == 1)
        {
            if (n % 2 == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    if (i == skip)
                        continue;
                    a[i] |= (1ll << k);
                }
                skip = min(skip + 1, n - 1);
            }
            else 
            {
                for (int i = 0; i < n; i++)
                    a[i] |= (1ll << k);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
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
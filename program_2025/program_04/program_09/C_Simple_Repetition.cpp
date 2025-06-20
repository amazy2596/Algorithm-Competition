#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x, k;
    cin >> x >> k;

    if (x == 1)
    {
        if (k == 2)
            cout << "YES\n";
        else 
            cout << "NO\n";
        return;
    }

    if (k >= 2)
    {
        cout << "NO\n";
        return;
    }

    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

    // for (int i = 1; i <= 100; i++)
    // {
    //     for (int k = 1; k <= 7; k++)
    //     {
    //         string x = "";
    //         for (int j = 1; j <= k; j++)
    //             x += to_string(i);

    //         int y = 0;
    //         for (int j = 0; j < x.length(); j++)
    //             y = (y * 10 + x[j] - '0');

    //         bool isPrime = 1;
    //         for (int j = 2; j <= sqrt(y); j++)
    //         {
    //             if (y % j == 0)
    //             {
    //                 isPrime = 0;
    //                 break;
    //             }
    //         }

    //         cout << y << " " << (isPrime ? "YES\n" : "NO\n");
    //     }
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
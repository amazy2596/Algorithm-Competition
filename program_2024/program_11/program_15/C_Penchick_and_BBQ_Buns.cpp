#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    // map<int, int> mp;
    // for (int i = 1; i <= 1000; i++)
    //     mp[i * i]++;
    // int count = 0;
    // for (int i = 1; i <= 1000; i++)
    // {
    //     for (int j = i + 1; j <= 1000; j++)
    //     {
    //         int x = i * i, y = j * j;
    //         if (mp.find(y - x) != mp.end())
    //         {
    //             cout << y - x << "\n";
    //             cout << x << " " << y << "\n";
    //             return;
    //         }
    //         else
    //         {
    //             cout << ++count << ": NO\n";
    //         }
    //     }
    // }
    int n;
    cin >> n;
    if (n % 2 == 1)
    {
        if (n < 26)
        {
            cout << -1 << "\n";
            return;
        }
        vector<int> a(n + 1);
        a[1] = 1, a[10] = 1, a[26] = 1;
        a[23] = a[27] = 2;
        int num = 3;
        for (int i = 2; i <= n; i++)
        {
            if (a[i] == 0)
            {
                a[i] = num;
                a[i + 1] = num;
                num++;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << " \n"[i == n];
    }
    else
    {
        for (int i = 1, j = 0; j < n; i++, j += 2)
            cout << i << " " << i << " ";
        cout << "\n";
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
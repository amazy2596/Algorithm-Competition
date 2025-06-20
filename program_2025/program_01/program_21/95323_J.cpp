#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    // for (int i = 1; i < 10000; i++)
    // {
    //     for (int j = i + 1; j < 10000; j++)
    //     {
    //         if ((i ^ j) == __gcd(i, j))
    //         {
    //             // cout << i << " " << j << " " << (i ^ j) << "\n";
    //             if ((i / (j - i)) % 2 != 0)
    //             {
    //                 cout << i << " " << j << " " << (i ^ j) << "\n";
    //             }
    //         }
    //     }
    // }

    int ans = 0;
    for (auto x : a)
    {
        if (x % 2 != 0)
            continue;
        
        int cnt = x / 2;
        vector<int> div;
        for (int d = 1; d <= sqrt(cnt); d++)
        {
            if (cnt % d == 0)
            {
                div.push_back(d);
                int y = x + d;
                if (mp.find(y) != mp.end() && (x ^ y) == __gcd(x, y))
                {
                    // cout << x << " " << y << " " << (x ^ y) << "\n";
                    ans += mp[y];
                }
                if (d != cnt / d)
                {
                    int temp = cnt / d;
                    y = x + temp;
                    if (mp.find(y) != mp.end() && (x ^ y) == __gcd(x, y))
                    {
                        // cout << x << " " << y << " " << (x ^ y) << "\n";
                        ans += mp[y];
                    }
                }
            }
        }
    }
    cout << ans << "\n";
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
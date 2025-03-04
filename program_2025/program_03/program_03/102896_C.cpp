#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    // for (int x = 1e9; x <= 1e9; x++)
    // {
        int x;
        cin >> x;
        auto get = [](int t)
        {
            map<int, int> mp;
            while (t)
            {
                mp[t % 10]++;
                t /= 10;
            }
            return mp;
        };

        map<int, int> tar = get(x);
        bool f = 1;
        for (int i = 1; i <= 17; i++)
        {
            int y = pow(10, i) + 1;
            map<int, int> cur = get(x * y);
            bool ff = 1;
            for (auto [key, val] : cur)
            {
                if (tar.find(key) == tar.end())
                    ff = 0;
            }
                
            if (ff)
            {
                f = 0;
                // cout << "x: " << x << " y: " << y << " mul: " << x * i << "\n";
                cout << y << "\n";
                break;
            }
        }
        // if (f)
        // {
            // cout << "x: " << x << "\n";
            // return;
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
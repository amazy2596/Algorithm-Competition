#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    if ((*mp.begin()).second >= 2)
        cout << "Yes\n";
    else 
    {
        int mn = (*mp.begin()).first;
        int g = 0;
        for (auto [key, val] : mp)
        {
            if (key % mn == 0 && key != mn)
            {
                g = __gcd(g, key);
            }
        }

        cout << (g == mn ? "Yes\n" : "No\n");
    }
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
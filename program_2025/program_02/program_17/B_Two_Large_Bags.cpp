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

    bool f = 1;
    for (auto [key, val] : mp)
    {
        if (val % 2 == 1)
            f = 0;
    }

    if (f)
    {
        cout << "Yes\n";
        return;
    }

    int last = 0, tar = (*mp.begin()).first;
    while (true)
    {
        int val = last;
        if (mp.find(tar) != mp.end())
            val += mp[tar];
        
        if (val == 1)
        {
            cout << "No\n";
            return;
        }

        last = max(0ll, val - 2);
        tar++;

        if (tar > (*mp.rbegin()).first)
            break;
    }

    cout << "Yes\n";
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
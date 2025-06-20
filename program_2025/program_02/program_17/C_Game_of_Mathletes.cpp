#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for (auto &x : a)
    {
        cin >> x;
        mp[x]++;
    }

    int ans = 0;
    for (auto &[a, val] : mp)
    {
        int b = k - a;
        if (mp.find(b) == mp.end())
        {
            ans += val;
            mp[a] = 0;
        }
        else 
        {
            if (a == b)
                ans += (mp[a] % 2);
            else
                ans += (max(val, mp[b]) - min(val, mp[b]));
            mp[a] = mp[b] = 0;
        }
    }

    cout << (n - ans) / 2 << "\n";
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
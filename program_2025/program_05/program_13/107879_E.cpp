#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int r = a[i] + 1, l = a[i] - 1;
        if (mp.find(r) == mp.end())
            mp[r]++;
        else if (mp.find(l) == mp.end())
            mp[l]++;
        else 
        {
            cout << "NO\n";
            return;
        }
    }

    int have = 0, time = 0;
    for (auto [key, val] : mp)
    {
        have += key - time;
        time = key;
        if (have >= 2)
            have -= 2;
        else 
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
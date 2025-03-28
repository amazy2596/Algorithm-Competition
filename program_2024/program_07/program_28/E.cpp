#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    bool f = 1;
    int mex = 0;
    if (mp.find(0) != mp.end())
    {
        f = 0;
        mex = 1;
        mp[0]--;
        if (mp[0] == 0)
            mp.erase(0);
    }
    for (int i = 1; i <= 1e6 + 5; i++)
    {
        for (int k = 0; k <= 21; k++)
        {
            if (mp.find(i * (1ll << k)) != mp.end())
            {
                mex = i + 1;
                mp[i * (1ll << k)]--;
                if (mp[i * (1ll << k)] == 0)
                    mp.erase(i * (1ll << k));
                break;
            }
        }
        if (mex != i + 1)
            break;
    }
    if (f && mp.empty())
        mex--;
    cout << mex << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
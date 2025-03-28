#include <bits/stdc++.h>
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
    int mex = 0;
    bool f = 1;
    while (true)
    {
        if (mp.find(mex) == mp.end())
            break;
        if (mp[mex] >= 2)
            mex++;
        else if (f && mp[mex] == 1)
            f = 0, mex++;
        else
            break;
    }
    cout << mex << "\n";
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
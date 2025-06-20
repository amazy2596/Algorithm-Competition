#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int mex = 0, cnt = 0;
    map<int, multiset<int>> mp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == cnt)
            mex++, cnt++;
        else
            mp[a[i] % x].insert(a[i]);
    }
    while (mp.find(cnt % x) != mp.end() && *mp[cnt % x].begin() <= cnt)
    {
        mex++;
        mp[cnt % x].erase(mp[cnt % x].begin());
        if (mp[cnt % x].size() == 0)
            mp.erase(cnt % x);
        cnt++;
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
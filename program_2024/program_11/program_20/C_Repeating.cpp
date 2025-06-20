#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> b(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (mp.find(x) != mp.end())
            b[i] = mp[x];
        mp[x] = i;
    }
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
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
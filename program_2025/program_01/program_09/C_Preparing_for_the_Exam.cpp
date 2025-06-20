#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    map<int, int> mp;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    if (n - 1 > k)
    {
        for (int i = 0; i < m; i++)
            cout << 0;
        cout << "\n";
        return;
    }

    int dont = -1;
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) == mp.end())
        {
            dont = i;
            break;
        }
    }

    string ans = "";
    for (int i = 0; i < m; i++)
    {
        if (a[i] == dont || dont == -1)
            ans += '1';
        else
            ans += '0';
    }
    cout << ans << "\n";
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
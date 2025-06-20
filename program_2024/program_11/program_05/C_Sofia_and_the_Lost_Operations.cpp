#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int m;
    cin >> m;
    vector<int> d(m);
    map<int, int> mp;
    for (int i = 0; i < m; i++)
    {
        cin >> d[i];
        mp[d[i]]++;
    }
    bool f = 0;
    for (auto x : b)
        if (x == d.back())
            f = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            continue;
        if (mp.find(b[i]) != mp.end() && mp[b[i]] > 0)
            mp[b[i]]--;
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << (f ? "YES\n" : "NO\n");
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
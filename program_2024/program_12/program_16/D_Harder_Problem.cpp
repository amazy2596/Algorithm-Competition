#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    queue<int> q;
    vector<int> a(n), ans(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end())
            ans[i] = a[i];
        mp[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) == mp.end())
            q.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 0)
        {
            ans[i] = q.front();
            q.pop();
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
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
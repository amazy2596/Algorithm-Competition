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
        cin >> a[i], mp[a[i]]++;
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] > a[i])
                cnt++;
        }
        ans = min(ans, i + cnt);
    }
    cout << ans << "\n";
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
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (mp.find(x) == mp.end())
            a.push_back(x);
        mp[x]++;
    }
    sort(a.begin(), a.end());
    int l = 0, r = 1;
    int cur = mp[a[0]], ans = mp[a[0]];
    while (l <= r && r < a.size())
    {
        if (a[r - 1] + 1 == a[r])
        {
            if (a[r] - a[l] + 1 <= k)
            {
                cur += mp[a[r++]];
                ans = max(ans, cur);
            }
            else
                cur -= mp[a[l++]];
        }
        else
        {
            l = r++;
            cur = mp[a[l]];
            ans = max(ans, cur);
        }
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
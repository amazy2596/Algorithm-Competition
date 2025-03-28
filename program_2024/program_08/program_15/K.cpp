#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp, mp1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    mp1 = mp;
    sort(a.begin(), a.end());
    int cnt = 0;
    int ans = mp[0];
    mp[0] = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        while (a[i] > cnt && mp[a[i]] > 0)
        {
            cnt++;
            mp[a[i]]--;
            ans += mp[cnt];
            mp[cnt] = 0;
        }
    }
    for (int i = 0; i < n && a[i] < 0; i++)
    {
        while (a[i] < cnt && mp[a[i]] > 0)
        {
            cnt--;
            mp[a[i]]--;
            ans += mp[cnt];   
            mp[cnt] = 0;
        }
    }
    int cnt1 = 0;
    int ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        while (a[i] < cnt1 && mp1[a[i]] > 0)
        {
            cnt1--;
            mp1[a[i]]--;
            ans1 += mp1[cnt1];   
            mp1[cnt1] = 0;
        }
    }
    for (int i = a.size() - 1; i >= 0; i--)
    {
        while (a[i] > cnt1 && mp1[a[i]] > 0)
        {
            cnt1++;
            mp1[a[i]]--;
            ans1 += mp1[cnt1];
            mp1[cnt1] = 0;
        }
    }
    cout << max(ans, ans1) << "\n";
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
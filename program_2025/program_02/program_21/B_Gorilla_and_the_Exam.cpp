#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    int ans = mp.size();
    vector<pair<int, int>> a;
    for (auto [key, val] : mp)
        a.push_back({val, key});
    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
    {
        if (k >= a[i].first)
            ans--, k -= a[i].first;
    }

    cout << max(1ll, ans) << "\n";
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
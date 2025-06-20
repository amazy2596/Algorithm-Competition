#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        int b, c;
        cin >> b >> c;
        mp[b] += c;
    }
    for (auto m : mp)
        a.push_back(m.second);
    sort(a.begin(), a.end());
    int ans = 0;
    while (n-- && !a.empty())
    {
        ans += a.back();
        a.pop_back();
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
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end());
    int ans = 0;
    int last = 0;
    for (auto [l, r] : a)
    {
        if (last < l)
        {
            ans += r - l + 1;
            last = r;
        }
        else if (last < r)
        {
            ans += r - last;
            last = r;
        }
    }

    cout << ans << "\n";
}

int main()
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
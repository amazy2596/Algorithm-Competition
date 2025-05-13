#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n), p(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].first *= (i + 1);
        a[i].second = i;
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a.begin(), a.end(), greater<pair<int, int>>());
    sort(b.begin(), b.end(), greater<int>());

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[a[i].second] = b[i];

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
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
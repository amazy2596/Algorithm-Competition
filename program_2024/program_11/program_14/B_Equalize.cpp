#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++)
        cin >> a[i], s.insert(i + 1);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int l = 0, ans = 0;
    for (int r = 0; r < a.size(); r++)
    {
        while (a[r] - a[l] > n - 1)
            l++;
        ans = max(ans, r - l + 1);
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
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [&](pair<int, int> &a, pair<int, int> &b)
    {
        // return a.first + a.second < b.first + b.second;
        return min(a.first, a.second) < min(b.first, b.second);
    });
    for (int i = 0; i < n; i++)
        cout << a[i].first << " " << a[i].second << " ";
    cout << "\n";
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
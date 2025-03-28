#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<int> v;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[0][i] > a[1][i])
        {
            v.push_back(a[1][i]);
            ans += a[0][i];
        }
        else
        {
            v.push_back(a[0][i]);
            ans += a[1][i];
        }
    }
    cout << ans + *max_element(v.begin(), v.end()) << "\n";
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
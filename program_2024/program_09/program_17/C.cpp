#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> row, col;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        row[x].push_back(y);
        col[y].push_back(x);
    }
    int ans = 0;
    for (auto [key, v] : row)
        ans = max(ans, *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()));
    for (auto [key, v] : col)
        ans = max(ans, *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()));
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
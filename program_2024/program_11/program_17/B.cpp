#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto query = [&](int x1, int y1, int x2, int y2) -> int
    {
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                if (a[i][j] == '*')
                    return -1;
            }
        }        
        return (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1);
    };
    pair<pair<int, int>, pair<int, int>> ans;
    int cur = 0;
    for (int x1 = 0; x1 < n; x1++)
    {
        for (int y1 = 0; y1 < m; y1++)
        {
            for (int x2 = x1; x2 < n; x2++)
            {
                for (int y2 = y1; y2 < n; y2++)
                {
                    int temp = query(x1, y1, x2, y2);
                    if (temp > cur)
                    {
                        cur = temp;
                        ans = {{x1, y1}, {x2, y2}};
                    }
                }
            }
        }
    }
    cout << ans.first.first + 1 << " " << ans.first.second + 1 << " " << ans.second.first + 1 << " " << ans.second.second + 1;
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
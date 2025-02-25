#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    pair<int, int> ans = {-1, -1};
    int mx = INT64_MIN;
    for (int i = 1; i <= n; i++)
    {
        int x = 0, y = 0;
        for (int j = i; j <= n; j++)
        {
            if (a[i] > a[j])
                x++;
            else if (a[i] < a[j])
                y++;
            if (x - y > mx)
            {
                mx = x - y;
                ans = {i, j};
            }
        }
    }

    cout << ans.first << " " << ans.second << "\n";
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
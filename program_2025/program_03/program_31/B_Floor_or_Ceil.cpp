#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x, n, m;
    cin >> x >> n >> m;
    int N = min(64ll, n + m);
    vector dp_min(N + 1, vector<int>(N + 1, INT32_MAX)), dp_max(N + 1, vector<int>(N + 1, INT32_MIN));
    dp_min[0][0] = x, dp_max[0][0] = x;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= min(i, n); j++)
        {
            int k = i - j;

            if (k <= m)
            {
                dp_min[i][j] = min(dp_min[i][j], (int)ceil(dp_min[i - 1][j] * 1.0 / 2));
                dp_max[i][j] = max(dp_max[i][j], (int)ceil(dp_max[i - 1][j] * 1.0 / 2));
            }
            if (j > 0)
            {
                dp_min[i][j] = min(dp_min[i][j], (int)dp_min[i - 1][j - 1] / 2);
                dp_max[i][j] = max(dp_max[i][j], (int)dp_max[i - 1][j - 1] / 2);
            }
        }
    }

    int ans = *max_element(dp_max[N].begin(), dp_max[N].end());
    for (int i = 0; i <= N; i++)
    {
        if (dp_max[N][i] == 0)
        {
            ans = 0;
            break;
        }
    }

    cout << *min_element(dp_min[N].begin(), dp_min[N].end()) << " " << ans << "\n";
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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    int ans = 0;
    for (int k = 0; k <= min(n, y); k++)
    {
        int cur_x = x + k, cur_y = y - k, remain = n - k;
        int temp = 0;
        if (remain >= x + y)
            temp = (cur_x + 1) * cur_y + ((1 + cur_x) * cur_x) / 2;
        else 
        {
            if (remain <= cur_y)
                temp = (cur_x + 1) * remain;
            else 
            {
                temp += (cur_x + 1) * cur_y;
                remain -= cur_y;
                temp += cur_x * remain - (remain - 1) * remain / 2;
            }
        }

        ans = max(ans, temp);
    }

    cout << ans << "\n";
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
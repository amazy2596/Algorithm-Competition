#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    if (n == 1)
    {
        cout << x << "\n";
        return;
    }

    int cur = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int temp = cur | i;
        bool f = 1;
        for (int bit = 0; bit <= 31; bit++)
        {
            if (((x >> bit) & 1) == 0 && ((temp >> bit) & 1) == 1)
            {
                f = 0;
                break;
            }
        }
        if (temp > x || !f)
            break;

        ans.push_back(i);
        cur = temp;
        if (i == n - 2 && cur < x && (cur | (i + 1)) != x)
            break;
    }

    while (ans.size() < n)
        ans.push_back(x);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
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
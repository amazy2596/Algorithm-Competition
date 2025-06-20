#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    string low = to_string(l1 + l2), high = to_string(r1 + r2);
    while (low.length() < high.length())
        low = '0' + low;

    int n = high.length();
    vector<array<array<int, 2>, 2>> dp(n, {array<int, 2>{-1, -1}, array<int, 2>{-1, -1}});

    function<int(int, int, int)> dfs = [&](int bit, int e1, int e2) -> int
    {
        if (bit >= n)
            return 0;
        int res = dp[bit][e1][e2];
        if (res != -1)
            return res;
        
        int x = low[bit] - '0';
        int y = high[bit] - '0';
        x = e1 ? x : 0;
        y = e2 ? y : 9;

        for (int i = x; i <= y; i++)
        {
            res = max(res, dfs(bit + 1, e1 && i == x, e2 && i == y) + i);
            dp[bit][e1][e2] = res;
        }
        return res;
    };

    cout << dfs(0, 1, 1) << "\n";
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
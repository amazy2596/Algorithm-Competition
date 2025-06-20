#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        intt m, x;
        cin >> m >> x;
        vector<int> c(m + 1), h(m + 1);
        int sum = 0;
        for (int i = 1; i <= m; i++)
        {
            cin >> c[i] >> h[i];
            sum += h[i];
        }
        vector<intt> dp(sum + 1, 1e16);
        dp[0] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = sum; j >= h[i]; j--)
            {
                if (dp[j - h[i]] + c[i] <= (i - 1) * x)
                    dp[j] = min(dp[j], dp[j - h[i]] + c[i]);
            }
        }
        for (intt j = sum; j >= 0; j--)
        {
            if (dp[j] != 1e16)
            {
                cout << j << "\n";
                break;
            }
        }
    }
    return 0;
}
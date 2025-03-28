#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    vector<int> s(4);
    for (int i = 0; i < 4; i++)
        cin >> s[i];
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        vector<int> a(s[i] + 1);
        int sum = 0;
        for (int j = 1; j <= s[i]; j++)
            cin >> a[j], sum += a[j];
        sort(a.begin(), a.end());
        vector<vector<int>> dp(s[i] + 1, vector<int>(sum / 2 + 1, 0));
        int temp = 0;
        for (int j = 1; j <= s[i]; j++)
        {
            for (int k = 0; k <= sum / 2; k++)
            {
                dp[j][k] = dp[j - 1][k];
                if (k >= a[j])
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - a[j]] + a[j]);
                temp = max(temp, dp[j][k]);
            }
        }
        ans += max(temp, sum - temp);
    }
    cout << ans;
    return 0;
}
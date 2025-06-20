#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    char ch;
    vector<int> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> ch;
        x[i] = ch - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> ch;
        y[i] = ch - '0';
    }
    vector<vector<int>> dp(n + 2, vector<int>(3, 1e9));
    dp[n + 1][1] = 0;
    for (int i = n; i >= 1; i--)
        for (int j = 0; j < 3; j++)
            for (int k = -9; k <= 9; k++)
                for (int t = 0; t < 3; t++)
                    if (x[i] + k + t - 1 - y[i] == (j - 1) * 10)
                        dp[i][j] = min(dp[i][j], dp[i + 1][t] + abs(k));
    cout << min({dp[1][0], dp[1][1], dp[1][2]});
    return 0;
}
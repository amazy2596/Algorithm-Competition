#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= a[i]; j--)
            dp[j] += dp[j - a[i]];
    cout << dp[m] << "\n";
    return 0;
}
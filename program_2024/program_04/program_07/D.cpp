#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, p;
    cin >> n >> p;
    vector<intt> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i] %= p;
    vector<intt> dp(p, INT32_MAX);
    for (int i = 0; i < n; i++)
        dp[a[i]] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            dp[(j + a[i]) % p] = min(dp[(j + a[i]) % p], dp[j] + 1);
        }
    }
    cout << dp[0];
    return 0;
}
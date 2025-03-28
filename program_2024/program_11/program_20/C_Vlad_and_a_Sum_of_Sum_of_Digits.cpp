#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
vector<int> dp(N + 1);

void init()
{
    for (int i = 1; i <= N; i++)
    {
        int num = i, cnt = 0;
        while (num)
        {
            cnt += num % 10;
            num /= 10;
        }
        dp[i] = dp[i - 1] + cnt;
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << dp[n] << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    string s;
    cin >> s;
    int n = s.length();

    s = " " + s;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            dp[i][j] = j - i + 1;

    auto check = [&](string a, string b)
    {
        int len = a.length();
        for (int i = 0; i < b.length(); i++)
        {
            if (a[i % len] != b[i])
            {
                return 0;
            }
        }

        return 1;
    };

    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            for (int p = l; p < r; p++)
                dp[l][r] = min(dp[l][r], dp[l][p] + dp[p + 1][r]);

            string b = s.substr(l, len);
            for (int j = 1; j * j <= len; j++)
            {
                if (len % j == 0)
                {
                    string a = s.substr(l, j);
                    if (check(a, b))
                    {
                        int num = len / j;
                        int digit = 0;
                        while (num)
                            digit++, num /= 10;

                        dp[l][r] = min(dp[l][r], digit + 2 + dp[l][l + j - 1]);
                    }

                    a = s.substr(l, len / j);
                    if (len / j != j && check(a, b))
                    {
                        int num = j;
                        int digit = 0;
                        while (num)
                            digit++, num /= 10;

                        dp[l][r] = min(dp[l][r], digit + 2 + dp[l][l + len / j - 1]);
                    }
                }
            }
        }
    }

    cout << dp[1][n] << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    string l, r;
    cin >> l >> r;
    int n = l.length();
    l = " " + l;
    r = " " + r;
    vector<array<int, 4>> dp(n + 1, {inf, inf, inf, inf});

    // 0 - 下界
    // 1 - 上界
    // 2 - 上下界
    // 3 - 中间

    dp[0][2] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int last = 0; last < 4; last++)
        {
            if (dp[i - 1][last] == inf)
                continue;
            char mn = '0', mx = '9';
            if (last == 0 || last == 2)
                mn = l[i];
            if (last == 1 || last == 2)
                mx = r[i];

            for (char num = mn; num <= mx; num++)
            {
                int add = 0;
                if (l[i] == num)
                    add++;
                if (r[i] == num)
                    add++;

                int cur;
                if (last == 0 && num == mn)
                {
                    cur = 0;
                    dp[i][cur] = min(dp[i][cur], dp[i - 1][last] + add);
                }
                else if (last == 1 && num == mx)
                {
                    cur = 1;
                    dp[i][cur] = min(dp[i][cur], dp[i - 1][last] + add);
                }
                else if (last == 2)
                {
                    if (num == mn && num == mx)
                    {
                        cur = 2;
                        dp[i][cur] = min(dp[i][cur], dp[i - 1][last] + add);
                    }
                    else if (num == mn)
                    {
                        cur = 0;
                        dp[i][cur] = min(dp[i][cur], dp[i - 1][last] + add);
                    }
                    else if (num == mx)
                    {
                        cur = 1;
                        dp[i][cur] = min(dp[i][cur], dp[i - 1][last] + add);
                    }
                    else 
                    {
                        cur = 3;
                        dp[i][cur] = min(dp[i][cur], dp[i - 1][last] + add);
                    }
                }
                else 
                {
                    cur = 3;
                    dp[i][cur] = min(dp[i][cur], dp[i - 1][last] + add);
                }
            }
        }
    }

    cout << *min_element(dp[n].begin(), dp[n].end()) << "\n";

}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
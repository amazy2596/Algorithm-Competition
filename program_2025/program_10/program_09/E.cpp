#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

const int N = 305;
i64 dp[N][N][N][3];

void solve()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;
    s = " " + s;

    int all = 0;
    if (s[1] == '?')
    {
        all++;
        dp[1][1][0][0] = dp[1][0][1][1] = dp[1][0][0][2] = 1;
    }
    else
        dp[1][0][0][s[1] - 'a'] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (s[i] != '?')
        {
            int cur = s[i] - 'a';
            for (int last = 0; last < 3; last++)
            {
                if (last == cur) continue;

                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < N; k++)
                    {
                        dp[i][j][k][cur] += dp[i - 1][j][k][last];
                        dp[i][j][k][cur] %= mod;
                    }
                }
            }
        }
        else 
        {
            all++;
            for (int last = 0; last < 3; last++)
            {
                for (int cur = 0; cur < 3; cur++)
                {
                    if (last == cur) continue;

                    for (int j = 0; j < N; j++)
                    {
                        for (int k = 0; k < N; k++)
                        {
                            if (cur == 0 && j)
                            {
                                dp[i][j][k][cur] += dp[i - 1][j - 1][k][last];
                                dp[i][j][k][cur] %= mod;
                            }
                            
                            if (cur == 1)
                            {
                                dp[i][j][k][cur] += dp[i - 1][j][k - 1][last];
                                dp[i][j][k][cur] %= mod;
                            }

                            if (cur == 2 && all - j - k > 0)
                            {
                                dp[i][j][k][cur] += dp[i - 1][j][k][last];
                                dp[i][j][k][cur] %= mod;
                            }
                        }
                    }
                }
            }
        }
    }

    vector<vector<i64>> pre(N, vector<i64>(N));
    for (int i = 0; i < N; i++)
    {
        pre[i][0] = dp[n][i][0][0] + dp[n][i][0][1] + dp[n][i][0][2];
        pre[i][0] %= mod;
        for (int j = 1; j < N; j++)
        {
            pre[i][j] = pre[i][j - 1] + (dp[n][i][j][0] + dp[n][i][j][1] + dp[n][i][j][2]);
            pre[i][j] %= mod;
        }
    }

    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        i64 ans = 0;
        for (int i = 0; i <= min(x, all); i++)
        {
            int l = max(0, all - i - z), r = min(y, all - i);
            if (l > r) continue;
            ans += pre[i][r] - (l == 0 ? 0 : pre[i][l - 1]);
            ans %= mod;
        }

        cout << (ans % mod + mod) % mod << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
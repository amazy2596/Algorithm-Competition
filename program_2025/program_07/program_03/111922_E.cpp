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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, inf)));
    dp[0][0][0] = dp[0][1][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int v = 0; v < 2; v++)
        {
            for (int f1 = 0; f1 < 2; f1++)
            {
                for (int f2 = 0; f2 < 2; f2++)
                {
                    int ch = (s[i] - '0') ^ f1 ^ f2;
                    if (ch < v)
                        continue;
                    dp[i][ch][f1 ^ f2] = min(dp[i][ch][f1 ^ f2], dp[i - 1][v][f1] + a[i] * f2);
                }
            }
        }
    }

    cout << min({dp[n][0][0], dp[n][0][1], dp[n][1][0], dp[n][1][1]}) << "\n";
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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int N = 41;
int dp[N][N][N][N];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    array<int, 5> cnt = {};
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int c1 = cnt[1], c2 = cnt[2], c3 = cnt[3], c4 = cnt[4];

    for (int x1 = 0; x1 <= c1; x1++)
        for (int x2 = 0; x2 <= c2; x2++)
            for (int x3 = 0; x3 <= c3; x3++)
                for (int x4 = 0; x4 <= c4; x4++)
                    dp[x1][x2][x3][x4] = -inf;

    dp[0][0][0][0] = a[1];
    for (int x1 = 0; x1 <= c1; x1++)
    {
        for (int x2 = 0; x2 <= c2; x2++)
        {
            for (int x3 = 0; x3 <= c3; x3++)
            {
                for (int x4 = 0; x4 <= c4; x4++)
                {
                    int cur = dp[x1][x2][x3][x4];
                    if (cur < 0)
                        continue;

                    int pos = 1 + x1 * 1 + x2 * 2 + x3 * 3 + x4 * 4;
                    if (x1 < c1 && pos + 1 <= n)
                        dp[x1 + 1][x2][x3][x4] = max(dp[x1 + 1][x2][x3][x4], cur + a[pos + 1]);
                    if (x2 < c2 && pos + 2 <= n)
                        dp[x1][x2 + 1][x3][x4] = max(dp[x1][x2 + 1][x3][x4], cur + a[pos + 2]);
                    if (x3 < c3 && pos + 3 <= n)
                        dp[x1][x2][x3 + 1][x4] = max(dp[x1][x2][x3 + 1][x4], cur + a[pos + 3]);
                    if (x4 < c4 && pos + 4 <= n)
                        dp[x1][x2][x3][x4 + 1] = max(dp[x1][x2][x3][x4 + 1], cur + a[pos + 4]);
                }
            }
        }
    }

    cout << dp[c1][c2][c3][c4] << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
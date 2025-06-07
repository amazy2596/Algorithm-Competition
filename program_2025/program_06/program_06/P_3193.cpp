#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;
int mod;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

vector<vector<int>> matrix_mul(vector<vector<int>> a, vector<vector<int>> b)
{
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                res[i][j] += a[i][k] * b[k][j], res[i][j] %= mod;
        }
    }
    
    return res;
}

vector<vector<int>> matrix_power(vector<vector<int>> a, int b)
{
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while (b)
    {
        if (b & 1)
            res = matrix_mul(res, a);
        a = matrix_mul(a, a);
        b >>= 1;
    }

    return res;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    mod = k;
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];

        if (s[j] == s[i])
            j++;
        
        pi[i] = j;
    }

    vector T(m, vector<int>(m));
    vector transfer(m, vector<int>(10, 0));
    for (int i = 0; i < m; i++)
    {
        for (char d = '0'; d <= '9'; d++)
        {
            int j = i;
            while (j > 0 && s[j] != d)
                j = pi[j - 1];

            if (s[j] == d)
                j++;

            if (j < m)
            {
                transfer[i][d - '0'] = j;
                T[i][j]++;
            }
        }
    }

    auto res = matrix_power(T, n);

    int ans = 0;
    for (int j = 0; j < m; j++)
        ans = (ans + res[0][j]) % mod;

    cout << ans << "\n";

    // vector dp(n + 1, vector<int>(m + 1, 0));
    // dp[0][0] = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         for (int d = 0; d <= 9; d++)
    //         {
    //             dp[i][transfer[j][d]] += dp[i - 1][j];
    //         }
    //     }
    // }
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
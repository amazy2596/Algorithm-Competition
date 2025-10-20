// Problem: D. Inversion Value of a Permutation
// URL: https://codeforces.com/contest/2145/problem/D
// Author: amazy
// Date: 2025-10-20 17:20:46

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



void solve()
{
    int n, k;
    cin >> n >> k;

    int m = n * (n - 1) / 2 - k;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<int>> choice(n + 1, vector<int>(m + 1, -1));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (!dp[i][j]) continue;
            for (int k = 1; i + k <= n; k++)
            {
                int j2 = j + k * (k - 1) / 2;
                if (j2 > m) break;
                if (!dp[i + k][j2])
                {
                    dp[i + k][j2] = 1;
                    choice[i + k][j2] = k;
                }
            }
        }
    }

    if (!dp[n][m])
    {
        cout << "0\n";
        return;
    }

    vector<int> lens;
    int i = n, j = m;
    while (i > 0)
    {
        int len = choice[i][j];
        lens.push_back(len);
        i -= len;
        j -= len * (len - 1) / 2;
    }

    vector<int> p;
    int mx = n;
    for (auto it = lens.rbegin(); it != lens.rend(); it++)
    {
        int len = *it;
        int l = mx - len + 1, r = mx;
        for (int val = l; val <= r; val++) p.push_back(val);
        mx -= len;
    }

    for (auto x : p) cout << x << " ";
    cout << "\n";
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
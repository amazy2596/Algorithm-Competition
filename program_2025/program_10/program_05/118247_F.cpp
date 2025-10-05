// Problem: Bracket Counting
// URL: https://ac.nowcoder.com/acm/contest/118247/F
// Author: amazy
// Date: 2025-10-05 20:28:44

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
    int n;
    cin >> n;

    vector<i64> sum(n), minpre(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '(') sum[i]++;
            else sum[i]--;
            minpre[i] = min(minpre[i], sum[i]);
        }
    }

    int m = 1LL << n;
    vector<i64> pre(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1) 
                pre[i] += sum[j];
        }
    }
    if (pre[m - 1] != 0)
    {
        cout << "0\n";
        return;
    }

    vector<i64> dp(m);
    dp[0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!((i >> j) & 1) && pre[i] + minpre[j] >= 0)
            {
                dp[i | (1 << j)] = (dp[i | (1 << j)] + dp[i]) % mod;
            }
        }
    }

    cout << dp[m - 1] % mod << "\n";
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
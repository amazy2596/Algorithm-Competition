// Problem: B. Abraham's Great Escape
// URL: https://codeforces.com/contest/2155/problem/B
// Author: amazy
// Date: 2025-10-06 15:46:06

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
    if (n * n - k == 1)
    {
        cout << "NO\n";
        return;
    }

    vector<vector<char>> ans(n + 1, vector<char>(n + 1, '#'));
    int cur = 0;
    bool f = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cur < k) 
            {
                ans[i][j] = 'U';
                cur++;
            }
            else 
            {
                if (f && i == n)
                {
                    for (int k = j; k < n; k++)
                        ans[i][k] = 'R';
                    ans[i][n] = 'L';
                }
                else if (f)
                {
                    for (int k = j; k < n; k++)
                        ans[i][k] = 'R';
                    for (int k = i; k < n; k++)
                        ans[k][n] = 'D';
                }
                f = 0;
                break;
            }
        }
    }
    if (ans[n][n] == '#') ans[n][n] = 'U';
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ans[i][j] == '#') 
                ans[i][j] = 'R';

            cout << ans[i][j];
        }
        cout << "\n";
    }
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
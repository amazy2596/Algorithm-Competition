// Problem: C. Against the Difference
// URL: https://codeforces.com/contest/2136/problem/C
// Author: amazy
// Date: 2025-08-28 23:04:36

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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    map<int, vector<int>> idx;
    vector<int> last(n + 1);
    for (int i = 1; i <= n; i++)
    {
        auto &v = idx[a[i]];
        v.push_back(i);

        if (a[i] - 1 < v.size())
            last[i] = *(v.rbegin() + a[i] - 1);
    }

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (last[i] == 0)
            dp[i] = dp[i - 1];
        else 
            dp[i] = max({dp[i - 1], dp[last[i] - 1] + a[i]});
    }

    cout << dp[n] << "\n";
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
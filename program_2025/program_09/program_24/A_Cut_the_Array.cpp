// Problem: A. Cut the Array
// URL: https://codeforces.com/contest/2144/problem/A
// Author: amazy
// Date: 2025-09-24 17:05:19

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
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int l = 1; l <= n; l++)
    {
        for (int r = l + 1; r <= n; r++)
        {
            int s1 = pre[l] % 3;
            int s2 = (pre[r] - pre[l]) % 3;
            int s3 = (pre[n] - pre[r]) % 3;

            if (s1 == s2 && s2 == s3)
            {
                cout << l << " " << r << "\n";
                return;
            }
            
            if (s1 != s2 && s1 != s3 && s2 != s3)
            {
                cout << l << " " << r << "\n";
                return;
            }
        }
    }

    cout << "0 0\n";
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
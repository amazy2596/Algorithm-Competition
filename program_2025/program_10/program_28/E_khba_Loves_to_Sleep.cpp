// Problem: E. khba Loves to Sleep!
// URL: https://codeforces.com/contest/2167/problem/E
// Author: amazy
// Date: 2025-10-28 22:57:29

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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());

    vector<int> ans;
    auto check = [&](int tar)
    {
        ans.clear();
        for (int j = 0; j <= a[1] - tar && ans.size() < k; j++) 
        {
            if (ans.empty() || j != ans.back()) ans.push_back(j);
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = a[i - 1] + tar; j <= a[i] - tar && ans.size() < k; j++)
            {
                if (ans.empty() || j != ans.back()) ans.push_back(j);
            }
        }
        for (int j = a[n] + tar; j <= x && ans.size() < k; j++)
        {
            if (ans.empty() || j != ans.back()) ans.push_back(j);
        }

        return ans.size() >= k;
    };

    int l = 0, r = x + 1;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else 
            r = mid - 1;
    }

    check(l);
    for (int i = 0; i < k; i++) cout << ans[i] << " ";
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
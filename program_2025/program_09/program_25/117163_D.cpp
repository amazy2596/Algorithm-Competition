// Problem: 小苯的平衡序列
// URL: https://ac.nowcoder.com/acm/contest/117163/D
// Author: amazy
// Date: 2025-09-25 22:30:36

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
    vector<i64> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];

    i64 ans = INF;
    for (int i = 1; i <= n; i++)
    {
        int mid = n / 2 + (n & 1);
        if (n % 2 == 0 && i <= mid)
            mid++;
        else if (n % 2 == 1 && i >= mid)
            mid--;

        i64 cur = 0;
        if (i <= mid)
        {
            cur += (mid - 2) * a[mid];
            cur -= pre[mid - 1] - a[i];
            cur += pre[n] - pre[mid];
            cur -= (n - mid) * a[mid];
        }
        else 
        {
            cur += (mid - 1) * a[mid];
            cur -= pre[mid - 1];
            cur += pre[n] - pre[mid] - a[i];
            cur -= (n - mid - 1) * a[mid];
        }
        ans = min(ans, cur);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
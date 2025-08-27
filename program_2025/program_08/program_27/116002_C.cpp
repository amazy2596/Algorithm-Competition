// Problem: 小苯的波浪加密器
// URL: https://ac.nowcoder.com/acm/contest/116002/C
// Author: amazy
// Date: 2025-08-27 15:06:55

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
    i64 n, l1, r1, l2, r2;
    cin >> n >> l1 >> r1 >> l2 >> r2;

    vector<int> a(n + 1);
    for (int i = 3; i <= n; i++)
        cin >> a[i];

    pair<i64, i64> ans = {INF, INF};
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            i64 a1 = l1;
            while (a1 <= min(r1, l1 + 10))
            {
                if (a1 % 10 == i)
                    break;
                a1++;
            }

            if (a1 > r1 || a1 % 10 != i) continue;

            i64 a2 = l2;
            while (a2 <= min(r2, l2 + 10))
            {
                if (a2 % 10 == j)
                    break;
                a2++;
            }

            if (a2 > r2 || a2 % 10 != j) continue;

            if ((a1 * a2) % 10 == a[3])
            {
                if (n == 3 || (n >= 4 && (a2 * a[3]) % 10 == a[4]))
                    ans = min(ans, make_pair(a1, a2));
            }
        }
    }
    if (ans.first == INF)
        cout << "-1 -1\n";
    else
        cout << ans.first << " " << ans.second << "\n";
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
// Problem: 牛牛的子序列
// URL: https://ac.nowcoder.com/acm/contest/116657/D
// Author: amazy
// Date: 2025-09-05 19:56:55

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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    vector<int> tmp_a, tmp_b;
    for (int i = 1; i <= n; i++)
    {
        if (tmp_a.empty() || tmp_a.back() != a[i])
            tmp_a.push_back(a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        if (tmp_b.empty() || tmp_b.back() != b[i])
            tmp_b.push_back(b[i]);
    }

    if (tmp_a != tmp_b)
    {
        cout << "-1\n";
        return;
    }

    int i = 1, j = 1;
    int cnt_a = 0, cnt_b = 0;

    int ans = 0;
    while (i <= n && j <= m)
    {
        for (int k = i; k <= n; k++)
        {
            if (a[k] == a[i])
                cnt_a++;
            else 
                break;
        }
        for (int k = j; k <= m; k++)
        {
            if (b[k] == b[j])
                cnt_b++;
            else 
                break;
        }
        i += cnt_a;
        j += cnt_b;

        if (cnt_a > cnt_b)
        {
            cout << "-1\n";
            return;
        }

        int tmp = 0;
        while (cnt_a < cnt_b)
        {
            cnt_a *= 2;
            tmp++;
        }

        ans = max(ans, tmp);
        cnt_a = cnt_b = 0;
    }

    cout << ans << "\n";
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
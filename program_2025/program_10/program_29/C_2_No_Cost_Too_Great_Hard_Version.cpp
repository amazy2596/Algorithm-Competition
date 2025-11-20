// Problem: C2. No Cost Too Great (Hard Version)
// URL: https://codeforces.com/contest/2154/problem/C2
// Author: amazy
// Date: 2025-10-29 11:20:36

// Problem: C1. No Cost Too Great (Easy Version)
// URL: https://codeforces.com/contest/2154/problem/C1
// Author: amazy
// Date: 2025-10-29 11:05:23

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
    vector<i64> a(n + 1), b(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                mp[j]++;
                if (j != a[i] / j) mp[a[i] / j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (auto [key, val] : mp)
    {
        if (key == 1) continue;
        if (val >= 2)
        {
            cout << "0\n";
            return;
        }
    }

    i64 ans = INF;
    for (int i = 1; i <= n; i++)
    {
        int x = a[i] + 1;
        for (int j = 2; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                if (mp.contains(j) || mp.contains(x / j)) 
                {
                    ans = min(ans, b[i]);
                }
            }
        }
        if (mp.contains(x)) ans = min(ans, b[i]);
    }

    vector<pair<i64, i64>> p(n + 1);
    for (int i = 1; i <= n; i++)
        p[i] = {a[i], b[i]};
    sort(p.begin() + 1, p.end(), [&](pair<i64, i64> &x, pair<i64, i64> &y){
        return x.second < y.second;
    });
    ans = min(ans, p[1].second + p[2].second);

    map<int, int> mp1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j * j <= p[i].first; j++)
        {
            if (p[i].first % j == 0)
            {
                mp1[j]++;
                if (j != p[i].first / j) mp1[p[i].first / j]++;
            }
        }
    }

    auto get = [&](i64 a, i64 b)
    {
        i64 r = ((a % b) + b) % b;
        return (b - r) % b;
    };

    for (auto [key, val] : mp1)
    {
        if (key == 1) continue;
        ans = min(ans, get(p[1].first, key) * p[1].second);
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
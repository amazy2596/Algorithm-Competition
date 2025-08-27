// Problem: 小苯的数字变换
// URL: https://ac.nowcoder.com/acm/contest/116002/D
// Author: amazy
// Date: 2025-08-27 15:44:19

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

    i64 ans = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        int j = n - i + 1;
        unordered_map<int, int> mp1, mp2;
        int k = 0;
        int x = a[i];
        mp1[x] = k;
        while (true)
        {
            x ^= x / 2;
            k++;
            if (mp1.find(x) != mp1.end())   
                break;
            mp1[x] = k;
        }

        int y = a[j];
        k = 0;
        mp2[y] = k;
        while (true)
        {
            y ^= y / 2;
            k++;
            if (mp2.find(y) != mp2.end())
                break;
            mp2[y] = k;
        }

        int tmp = inf;
        for (auto [key, val] : mp1)
        {
            if (mp2.find(key) != mp2.end())
                tmp = min(tmp, val + mp2[key]);
        }

        if (tmp == inf)
        {
            cout << "-1\n";
            return;
        }

        ans += tmp;
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
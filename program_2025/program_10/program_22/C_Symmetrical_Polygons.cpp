// Problem: C. Symmetrical Polygons
// URL: https://codeforces.com/contest/2153/problem/C
// Author: amazy
// Date: 2025-10-22 10:46:37

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

int c = 0;

void solve()
{
    int n;
    cin >> n;

    // if (++c == 49)
    // {
    //     cout << "\n*****\n";
    //     cout << n << "\n";
    //     for (int i = 0; i < n; i++)
    //     {
    //         int x;
    //         cin >> x;
    //         cout << x << " ";
    //     }
    //     cout << "\n*****\n";
    // }

    map<i64, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    i64 sum = 0, mx = 0, siz = 0;
    vector<int> rem;
    for (auto &[key, val] : mp)
    {
        sum += val / 2 * 2 * key;
        siz += val / 2 * 2;
        if (val >= 2) mx = max(mx, key);
        val %= 2;
        if (val == 1) rem.push_back(key);
    }

    if (sum == 0)
    {
        cout << "0";
        cout << "\n";
        return;
    }

    i64 ans = sum;
    int add = 0;
    for (int i = 1; i < rem.size(); i++)
    {
        if ((sum + rem[i - 1] > rem[i]) || rem[i] <= mx)
        {
            add = max(add, 2);
            ans = max(ans, sum + rem[i - 1] + rem[i]);
        }
    }
    for (int i = 0; i < rem.size(); i++)
    {
        if (sum > rem[i] || rem[i] <= mx)
        {
            add = max(add, 1);
            ans = max(ans, sum + rem[i]);
        }
    }

    if (siz + add <= 2)
    {
        cout << "0\n";
        return;
    }

    cout << ans;
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
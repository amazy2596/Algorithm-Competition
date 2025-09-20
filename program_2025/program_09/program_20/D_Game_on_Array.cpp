// Problem: D. Game on Array
// URL: https://codeforces.com/contest/2147/problem/D
// Author: amazy
// Date: 2025-09-20 23:56:07

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
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mp[a[i]]++;

    map<int, set<int>> rev;
    for (auto [key, val] : mp)
        rev[val].insert(key);

    vector<i64> ans = {0, 0};
    int op = 0;
    while (true)
    {
        auto &[valX, st] = *rev.rbegin();
        set<int> toearse, toinsert;
        for (auto x : st)
        {
            auto it = mp.lower_bound(x);
            if (it == mp.begin())
            {
                if (x % 2 == 0)
                {
                    ans[op] += x / 2 * valX;
                    ans[op ^ 1] += x / 2 * valX;
                }
                else 
                {
                    ans[op] += (x / 2 + 1) * valX;
                    ans[op ^ 1] += x / 2 * valX;
                    op ^= 1;
                }
            }
            it--;

            auto [y, valY] = *it;
            int dist = valX - valY - 1;
            if (dist % 2 == 0)
            {
                ans[op] += dist / 2 * valX;
                ans[op ^ 1] += dist / 2 * valX;
            }
            else 
            {
                ans[op] += (dist / 2 + 1) * valX;
                ans[op ^ 1] += dist / 2 * valX;
                op ^= 1;
            }

            toearse.insert(x);
            mp.erase(x);

            toinsert.insert(y + 1);
            mp[y + 1] = valX;
        }
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
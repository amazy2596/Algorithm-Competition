// Problem: D. Beautiful Permutation
// URL: https://codeforces.com/contest/2162/problem/D
// Author: amazy
// Date: 2025-10-29 08:33:27

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

    map<tuple<int, int, int>, int> memo;
    auto query = [&](int type, int l, int r)
    {
        cout << type << " " << l << " " << r << endl;
        int res;
        cin >> res;
        return res;
    };

    i64 sum = query(2, 1, n);
    i64 diff = sum - n * (n + 1) / 2;

    auto len = [&](int l, int r)
    {
        return query(2, l, r) - query(1, l, r);
    };

    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (len(l, mid) > 0)
            r = mid;
        else 
            l = mid + 1;
    }

    cout << "! " << l << " " << l + diff - 1 << endl;
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

// 3 1 2
// 3 2 2

// 2 1 3 4
// 2 2 4 5

// 3
// 1 2 3
// 2 2 3
// 1 1
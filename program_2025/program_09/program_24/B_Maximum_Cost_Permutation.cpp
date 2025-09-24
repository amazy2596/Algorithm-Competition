// Problem: B. Maximum Cost Permutation
// URL: https://codeforces.com/contest/2144/problem/B
// Author: amazy
// Date: 2025-09-24 17:24:34

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
    vector<int> a(n + 1), idx;
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0) 
            idx.push_back(i);
        else 
            s.erase(a[i]);
    }

    auto it = s.rbegin();
    for (auto i : idx)
    {
        a[i] = *it;
        it++;
    }

    int l = 1;
    while (l <= n && a[l] == l)
        l++;
    int r = n;
    while (r >= 1 && a[r] == r)
        r--;

    cout << (l >= r ? 0 : r - l + 1) << "\n";
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
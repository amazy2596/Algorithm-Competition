// Problem: A. All Lengths Subtraction
// URL: https://codeforces.com/contest/2143/problem/A
// Author: amazy
// Date: 2025-09-25 10:14:09

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
    int l = -1, r = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == n) l = r = i;
    }
    a[l]--;

    while (l >= 1 && r <= n)
    {
        if (l - 1 >= 1 && a[l - 1] == a[l])
        {
            l--;
            for (int i = l; i <= r; i++) a[i]--;
        }
        else if (r + 1 <= n && a[r + 1] == a[r])
        {
            r++;
            for (int i = l; i <= r; i++) a[i]--;
        }
        else 
            break;
    }

    if (l == 1 && r == n)
        cout << "YES\n";
    else 
        cout << "NO\n";
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
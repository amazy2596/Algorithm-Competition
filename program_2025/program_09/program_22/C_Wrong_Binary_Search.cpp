// Problem: C. Wrong Binary Search
// URL: https://codeforces.com/contest/2146/problem/C
// Author: amazy
// Date: 2025-09-22 18:01:59

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
    string s;
    cin >> s;
    s = " " + s;

    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    for (int l = 1; l <= n; )
    {
        if (s[l] == '1')
        {
            l++;
            continue;
        }
        int r = l;
        while (s[r] == '0' && r <= n)
            r++;
        r--;

        for (int i = l; i < r; i++)
            swap(p[i], p[i + 1]);
        
        l = r + 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0' && p[i] == i)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << p[i] << " \n"[i == n];
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
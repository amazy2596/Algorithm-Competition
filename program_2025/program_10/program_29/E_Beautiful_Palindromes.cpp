// Problem: E. Beautiful Palindromes
// URL: https://codeforces.com/contest/2162/problem/E
// Author: amazy
// Date: 2025-10-29 09:29:27

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int x = -1, y, z;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            x = i;
            break;
        }
    }
    if (x == -1)
    {
        x = a[1];
        y = a[2];
        z = a[3];
    }
    else 
    {
        z = a[n];
        for (int i = 1; i <= n; i++)
        {
            if (i != x && i != z)   
            {
                y = i;
                break;
            }
        }
    }

    vector<int> tmp = {x, y, z};
    for (int i = 0; i < k; i++)
    {
        cout << tmp[i % 3] << " ";
    }
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

// 1 2 1 3 2 1
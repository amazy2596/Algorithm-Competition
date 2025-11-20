// Problem: F. Beautiful Intervals
// URL: https://codeforces.com/contest/2162/problem/F
// Author: amazy
// Date: 2025-10-29 10:29:00

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
    vector<int> st(n + 1), ed(n + 1), freq(n + 1);
    vector<pair<int, int>> seg(m);
    for (auto &[l, r] : seg)
    {
        cin >> l >> r;
        st[l] = 1;
        ed[r] = 1;
        for (int j = l; j <= r; j++) freq[j]++;
    }

    vector<int> p(n + 1, -1);
    auto fill = [&]()
    {
        vector<int> used(n);
        for (int i = 1; i <= n; i++) 
        {
            if (p[i] == -1) continue;
            used[p[i]]++;
        }

        int j = 0;
        for (int i = 1; i <= n; i++)
        {
            if (p[i] != -1) continue;
            while (used[j]) j++;
            used[j] = 1;
            p[i] = j;
        }
        for (int i = 1; i <= n; i++) cout << p[i] << " ";
        cout << "\n";
        return;
    };

    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == m)
        {
            p[i] = 0;
            fill();
            return;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (ed[i] == 0)
        {
            p[i] = 0;
            p[i + 1] = 1;
            fill();
            return;
        }
        if (st[i + 1] == 0)
        {
            p[i] = 1;
            p[i + 1] = 0;
            fill();
            return;
        }
    }

    p[1] = 0;
    p[2] = 2;
    p[3] = 1;
    fill();
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
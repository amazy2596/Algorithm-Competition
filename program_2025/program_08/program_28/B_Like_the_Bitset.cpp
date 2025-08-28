// Problem: B. Like the Bitset
// URL: https://codeforces.com/contest/2136/problem/B
// Author: amazy
// Date: 2025-08-28 22:42:41

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
    string s;
    cin >> s;
    s = " " + s;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += (s[i] == '1');

    if (cnt == 0)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << i << " \n"[i == n];
        return;
    }

    if (k == 1)
    {
        cout << "NO\n";
        return;
    }

    int cur = 1;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            ans[i] = cur++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
            ans[i] = cur++;
    }

    int l = 1, r = k;
    set<int> a, b;
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '1')
            a.insert(ans[i]);
        b.insert(ans[i]);
    }

    bool f = true;
    
    if (a.size() && b.size())
        f &= (*(b.rbegin()) != *(a.rbegin()));
    while (r + 1 <= n)
    {
        if (s[l] == '1')
            a.erase(ans[l]);
        b.erase(ans[l]);
        l++, r++;
        if (s[r] == '1')
            a.insert(ans[r]);
        b.insert(ans[r]);

        if (a.size() && b.size())
            f &= (*(b.rbegin()) != *(a.rbegin()));
    }

    if (!f)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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
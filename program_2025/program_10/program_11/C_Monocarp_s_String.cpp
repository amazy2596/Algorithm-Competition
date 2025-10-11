// Problem: C. Monocarp's String
// URL: https://codeforces.com/contest/2145/problem/C
// Author: amazy
// Date: 2025-10-11 20:05:27

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

    int tar = count(s.begin() + 1, s.end(), 'a') - count(s.begin() + 1, s.end(), 'b');
    map<int, int> last;
    int cur = 0;
    last[cur] = 0;
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        cur += (s[i] == 'a' ? 1 : -1);
        last[cur] = i;
        if (last.count(cur - tar))
            ans = min(ans, i - last[cur - tar]);
    }

    cout << (ans == n ? -1 : ans) << "\n";
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
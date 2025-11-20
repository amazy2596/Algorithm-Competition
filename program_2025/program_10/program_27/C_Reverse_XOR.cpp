// Problem: C. Reverse XOR
// URL: https://codeforces.com/contest/2160/problem/C
// Author: amazy
// Date: 2025-10-27 17:42:46

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
    while (n)
    {
        s.push_back((n & 1) + '0');
        n >>= 1;
    }

    reverse(s.begin(), s.end());
    while (!s.empty() && s.back() == '0')
        s.pop_back();

    int len = s.length();
    if (len % 2 == 1 && s[len / 2] == '1')
    {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
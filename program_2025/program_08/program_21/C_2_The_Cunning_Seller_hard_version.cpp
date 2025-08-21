// Problem: C2. The Cunning Seller (hard version)
// URL: https://codeforces.com/contest/2132/problem/C2
// Author: amazy
// Date: 2025-08-21 23:50:09

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

ostream &operator<<(ostream &os, i128 n) 
{
    if (n == 0) return os << 0;

    string s;
    while (n > 0) 
    {
        s += char('0' + n % 10);
        n /= 10;
    }
    reverse(s.begin(), s.end());

    return os << s;
}

void solve()
{
    i64 n, k;
    cin >> n >> k;

    if (k >= n)
    {
        cout << 3 * n << "\n";
        return;
    }

    string d;
    i64 tmp = n;
    while (tmp)
    {
        d += tmp % 3 + '0';
        tmp /= 3;
        k -= d.back() - '0';
    }

    if (k < 0)
    {
        cout << "-1\n";
        return;
    }

    vector<i128> pow3(d.length() + 5);
    pow3[0] = 1;
    for (int i = 1; i < d.length() + 5; i++)
        pow3[i] = pow3[i - 1] * 3;

    vector<i128> count(d.length());
    for (int i = d.length() - 1; i >= 0; i--)
    {
        count[i] += d[i] - '0';
        if (i >= 1)
        {
            i128 cnt = min(count[i], (i128)k / 2);
            count[i - 1] += 3 * cnt;
            count[i] -= cnt;
            k -= 2 * cnt;
        }
    }

    i128 fee = 0;
    for (int i = 0; i < count.size(); i++)
        fee += count[i] * (pow3[i + 1] + (i == 0 ? 0 : i * pow3[i - 1]));

    cout << fee << "\n";
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
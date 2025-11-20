// Problem: C. Beautiful XOR
// URL: https://codeforces.com/contest/2162/problem/C
// Author: amazy
// Date: 2025-10-29 08:28:26

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
    int a, b;
    cin >> a >> b;
    vector<int> op;
    for (int k = 0; k < 32; k++)
    {
        int bitA = (a >> k) & 1;
        int bitB = (b >> k) & 1;
        if (bitA != bitB) 
        {
            if ((1 << k) > a)
            {
                cout << "-1\n";
                return;
            }
            op.push_back(1 << k);
            a ^= (1 << k);
        }
    }
    cout << op.size() << "\n";
    for (auto x : op) cout << x << " ";
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
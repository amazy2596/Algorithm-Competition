// Problem: D. Destruction of the Dandelion Fields
// URL: https://codeforces.com/contest/2148/problem/D
// Author: amazy
// Date: 2025-09-13 23:16:26

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
    deque<int> odd, even;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
            even.push_back(a);
        else 
            odd.push_back(a);
    }

    if (odd.size() == 0)
    {
        cout << "0\n";
        return;
    }

    ranges::sort(odd);
    ranges::sort(even);

    i64 ans = 0;
    ans += odd.back();
    odd.pop_back();
    ans += accumulate(even.begin(), even.end(), 0LL);

    for (int i = 0; odd.size(); i++)
    {
        if (i % 2 == 0 && odd.size())
            odd.pop_front();
        else if (odd.size())
        {
            ans += odd.back();
            odd.pop_back();
        }
    }

    cout << ans << "\n";
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
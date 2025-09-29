// Problem: 小芳的排列构造
// URL: https://ac.nowcoder.com/acm/contest/117763/E
// Author: amazy
// Date: 2025-09-29 11:39:00

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
    i64 k;
    cin >> n >> k;

    if (n == 1 && k == 2)
    {
        cout << "1\n";
        return;
    }

    if (k < 2 * n + n - 1)
    {
        cout << "-1\n";
        return;
    }
    k -= 2 * n + n - 1;

    deque<int> ans = {n - 1};
    for (int i = n - 2; i >= 1; i--)
    {
        if (k >= i) ans.push_front(i), k -= i;
        else ans.push_back(i);
    }
    ans.push_back(n);

    if (k != 0)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
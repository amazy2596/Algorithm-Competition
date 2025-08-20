// Problem: 中位数+1
// URL: https://ac.nowcoder.com/acm/contest/115567/C
// Author: amazy
// Date: 2025-08-21 01:16:26

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
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (low.empty() || x <= low.top())
            low.push(x);
        else 
            high.push(x);

        if (low.size() < high.size())
            low.push(high.top()), high.pop();
        else if (low.size() > high.size() + 1)
            high.push(low.top()), low.pop();

        if (i % 2 == 1)
            cout << low.top() << " ";
        else 
            cout << (low.top() + high.top()) / 2 << " ";
    }
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
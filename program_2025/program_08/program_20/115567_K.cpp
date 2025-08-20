// Problem: 狂飙追击
// URL: https://ac.nowcoder.com/acm/contest/115567/K
// Author: amazy
// Date: 2025-08-21 02:06:00

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

struct node
{
    int x, y, step;

    bool operator<(const node o) const
    {
        return step > o.step;
    }
};

void solve()
{
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    priority_queue<node> q;
    q.push({sx, sy, 0});
    while (!q.empty())
    {
        auto [x, y, step] = q.top();
        q.pop();

        if (x > tx || y > ty)
            continue;

        if (x == tx && y == ty)
        {
            cout << step;
            return;
        }

        int m = max(x, y);
        if (x + m <= tx)
            q.push({x + m, y, step + 1});
        if (y + m <= ty)
            q.push({x, y + m, step + 1});
    }

    cout << "-1\n";
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
// Problem: [USACO12MAR] Flowerpot S
// URL: https://www.luogu.com.cn/problem/P2698
// Author: amazy
// Date: 2025-09-02 14:19:41

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

const int N = 1e6 + 5;

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>> idx(N);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        idx[x].push_back(y);
    }

    int ans = inf;
    deque<pair<int, int>> mx, mn;
    int l = 0, r = 0;
    while (r < N)
    {
        for (auto y : idx[r])
        {
            while (!mx.empty() && mx.back().second <= y)
                mx.pop_back();
            while (!mn.empty() && mn.back().second >= y)
                mn.pop_back();
            mx.push_back({r, y});
            mn.push_back({r, y});

            int diff = abs(mx.front().second - mn.front().second);
            while (diff >= d)
            {
                ans = min(ans, r - l);
                l++;
                while (!mx.empty() && mx.front().first < l)
                    mx.pop_front();
                while (!mn.empty() && mn.front().first < l)
                    mn.pop_front();
                diff = abs(mx.front().second - mn.front().second);
            }
        }
        r++;
    }

    cout << (ans == inf ? -1 : ans) << "\n";
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
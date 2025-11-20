// Problem: 小红的区间构造
// URL: https://ac.nowcoder.com/acm/contest/120553/E
// Author: amazy
// Date: 2025-11-06 11:18:44

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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];

    queue<pair<int, int>> ans;
    stack<int> st;
    for (int i = 1; i <= n + 1; i++)
    {
        int delta = a[i] - a[i - 1];
        if (delta > 0)
        {
            while (delta--) 
                st.push(i);
        }
        else if (delta < 0) 
        {
            while (delta++)
            {
                ans.push({st.top(), i - 1});
                st.pop();
            }
        }
    }

    if (ans.size() > m)
    {
        cout << "-1\n";
        return;
    }

    while (ans.size() < m)
    {
        auto [l, r] = ans.front();
        ans.pop();
        int i = l + 1;
        while (i <= r && ans.size() + 1 < m)
        {
            ans.push({i - 1, i});
            i++;
        }
        ans.push({i, r});
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
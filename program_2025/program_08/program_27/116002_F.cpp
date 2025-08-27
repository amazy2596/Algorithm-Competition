// Problem: 小苯的数组计数
// URL: https://ac.nowcoder.com/acm/contest/116002/F
// Author: amazy
// Date: 2025-08-27 17:59:00

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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> posl(n, -1), posr(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            auto j = s.top();
            s.pop();
            if (!s.empty())
                posl[j] = s.top();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        auto j = s.top();
        s.pop();
        if (!s.empty())
            posl[j] = s.top();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            auto j = s.top();
            s.pop();
            if (!s.empty())
                posr[j] = s.top();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        auto j = s.top();
        s.pop();
        if (!s.empty())
            posr[j] = s.top();
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (posl[i] != -1 && i - posl[i] > 1 && a[i] != a[posl[i]])
            ans++;
        if (posr[i] != -1 && posr[i] - i > 1 && a[i] != a[posr[i]])
            ans++;
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
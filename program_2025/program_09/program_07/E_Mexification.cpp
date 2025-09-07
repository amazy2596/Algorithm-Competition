// Problem: E. Mexification
// URL: https://codeforces.com/contest/2137/problem/E
// Author: amazy
// Date: 2025-09-07 23:28:39

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], cnt[a[i]]++;

    vector<int> vis(n + 1);
    set<int> s;
    auto tmp = a;
    ranges::sort(tmp);

    for (int i = 1; i <= n; i++)
    {
        if (tmp[i] <= s.size())
        {
            vis[tmp[i]] = 1;
            if (tmp[i] == s.size())
                s.insert(tmp[i]);
        }
    }

    int f = 0;
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        if (vis[i])
            f |= (cnt[i] >= 2);
        else 
            sum += cnt[i];
    }

    int mex = s.size();
    i64 ans = 0;
    if (!f)
    {
        for (int i = 1; i <= n; i++)
        {
            if (vis[a[i]]) 
                ans += a[i];
            else if (sum >= 2 && k % 2 == 0)
                ans += mex + 1;
            else 
                ans += mex;
        }

        cout << ans << "\n";
        return ;
    }

    int mn;
    for (int i = 0; i <= n; i++)
    {
        if (vis[i] && cnt[i] >= 2)
        {
            mn = i;
            break;
        }
    }

    if (k == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (vis[a[i]])
            {
                if (a[i] < mn || cnt[a[i]] == 1)
                    ans += a[i];
                else
                    ans += mex;
            }
            else 
                ans += mex;
        }
        cout << ans << "\n";
        return;
    }

    mex = mn;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < mn)
            ans += a[i];
        else if (k % 2 == 0)
            ans += mex;
        else 
            ans += mex + 1;
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
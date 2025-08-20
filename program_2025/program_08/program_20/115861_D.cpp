// Problem: 小苯的重排构造
// URL: https://ac.nowcoder.com/acm/contest/115861/D
// Author: amazy
// Date: 2025-08-20 22:59:52

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
    map<int, int> mp;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    sort(a.begin(), a.end());
    int mx = 0;
    for (int i = 1; i <= n - 1; i++)
        mx += gcd(a[i], a[i + 1]);

    int mn = min(mp[1], mp[2]) + (mp[2] > mp[1] ? 2 * (mp[2] - mp[1]) : mp[1] - mp[2]);

    if (k < mn || k > mx)
    {
        cout << "-1\n";
        return;
    }

    int cur = 0;
    vector<int> ans;
    if (mp[2])
        ans.push_back(2), mp[2]--;

    while (ans.size() < n)
    {
        int remain = n - ans.size();
        if (cur + remain < k && mp[2])
        {
            ans.push_back(2);
            mp[2]--;
            cur += 2;
        }
        else 
        {
            if (ans.back() == 2 && mp[1])
            {
                ans.push_back(1);
                mp[1]--;
            }
            else if (ans.back() == 1)
            {
                if (mp[2])
                {
                    ans.push_back(2);
                    mp[2]--;
                }
                else if (mp[1])
                {
                    ans.push_back(1);
                    mp[1]--;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
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
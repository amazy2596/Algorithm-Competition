// Problem: D. Find the Last Number
// URL: https://codeforces.com/contest/2156/problem/D
// Author: amazy
// Date: 2025-11-11 15:15:19

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
    
    auto query = [](int i, int x)
    {
        cout << "? " << i << " " << x << endl;
        int res;
        cin >> res;
        return res;
    };

    set<int> s, t;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
        if (i < n) t.insert(i);
    }

    for (int k = 0; s.size() > 1; k++)
    {
        int x = 0, y = 0;
        vector<pair<int, int>> res;
        for (auto val : t) 
        {
            int tmp = query(val, 1 << k);
            x += tmp;
            res.push_back({val, tmp});
        }
        for (auto val : s) y += ((val >> k) & 1);

        int bit = (x != y);
        vector<int> toerase;
        for (auto [val, tmp] : res)
        {
            if (bit != tmp)
            {
                t.erase(val);
            }
        }

        for (auto val : s)
        {
            if (bit != ((val >> k) & 1))
            {
                toerase.push_back(val);
            }
        }

        for (auto val : toerase) s.erase(val);
    }

    cout << "! " << *s.begin() << "\n";
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

// 1 2 3
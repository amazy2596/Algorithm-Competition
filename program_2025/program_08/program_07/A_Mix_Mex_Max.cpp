#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tmp[a[i]]++;
    }

    if (tmp.find(0) != tmp.end())
    {
        cout << "NO\n";
        return;
    }

    if (tmp.size() > 2)
    {
        cout << "NO\n";
        return;
    }

    // for (int i = 0; i + 2 < n; i++)
    // {
    //     if (a[i] != -1 && a[i + 1] != -1 && a[i + 2] != -1)
    //     {
    //         vector<int> tmp(a.begin() + i, a.begin() + i + 2);
    //         sort(tmp.begin(), tmp.end());
    //         int mn = tmp[0], mx = tmp[2];
    //         set<int> s;
    //         for (int i = 0; i < tmp.size(); i++)
    //             if (s.size() == tmp[i]) s.insert(tmp[i]);

    //         if (mx - mn != s.size())
    //         {
    //             cout << "NO\n";
    //             return;
    //         }
    //     }

    //     map<int, int> mp;
    //     mp[a[i]]++;
    //     mp[a[i + 1]]++;
    //     mp[a[i + 2]]++;

    //     // -1 2 3
    //     if (mp.size() == 3)
    //     {
    //         cout << "NO\n";
    //         return;
    //     }

    //     int tar = mp.rbegin()->first;
    //     for (int j = i; j <= i + 2; j++)
    //     {
    //         if (a[j] == -1)
    //             a[j] = tar;
    //     }
    // }

    cout << "YES\n";
}

signed main()
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
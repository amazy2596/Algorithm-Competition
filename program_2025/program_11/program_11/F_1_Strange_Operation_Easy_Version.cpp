// Problem: F1. Strange Operation (Easy Version)
// URL: https://codeforces.com/contest/2156/problem/F1
// Author: amazy
// Date: 2025-11-11 16:20:24

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
    vector<int> p(n + 1);
    set<int> s;
    for (int i = 1; i <= n; i++) 
    {
        cin >> p[i];
        s.insert(i);
    }

    int mn = 1;
    while (s.size())
    {
        if (p[*s.begin()] % 2 == 1)
        {
            int tmp = p[*s.begin()];
            p[*s.begin()] = mn;
            s.erase(s.begin());
            mn++;
            for (auto idx : s) if (p[idx] > tmp) p[idx]--;
        }
        else 
        {
            int pre = inf;
            for (auto i = s.begin(); i != s.end(); i++)
            {
                pre = min(pre, p[*i]);
                if (p[*i] % 2 == 1 && p[*i] == pre)
                {
                    auto j = s.begin();
                    if (p[*i] > p[*j])
                    {
                        int tmp = p[*i];
                        p[*i] = mn;
                        s.erase(*i);
                        for (auto idx : s) if (p[idx] > tmp) p[idx]--;

                        tmp = p[*j];
                        p[*j] = mn + 1;
                        s.erase(*j);
                        for (auto idx : s) if (p[idx] > tmp) p[idx]--;
                    }
                    else 
                    {
                        int tmp = p[*j];
                        p[*j] = mn + 1;
                        s.erase(*j);
                        for (auto idx : s) if (p[idx] > tmp) p[idx]--;

                        tmp = p[*i];
                        p[*i] = mn;
                        s.erase(*i);
                        for (auto idx : s) if (p[idx] > tmp) p[idx]--;
                    }
                    mn += 2;
                    break;
                }
            }
        }

    }

    for (int i = 1; i <= n; i++) cout << p[i] << " ";
    cout << "\n";
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
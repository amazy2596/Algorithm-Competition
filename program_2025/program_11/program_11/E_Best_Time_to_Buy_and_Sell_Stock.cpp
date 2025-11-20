// Problem: E. Best Time to Buy and Sell Stock
// URL: https://codeforces.com/contest/2156/problem/E
// Author: amazy
// Date: 2025-11-11 17:59:22

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
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    auto v = a;
    auto calc = [&](auto tar)
    {
        vector<int> L(n + 1), R(n + 1);
        vector<pair<int, int>> bucket(3, {inf + 1, 0});

        for (int i = 1; i <= n; i++)
        {
            if (v[i] == -1) continue;
            for (auto [val, c] : bucket)
            {
                if (v[i] - val >= tar)
                {
                    L[i] += c;
                }
            }

            for (int j = 0; j < 3; j++)
            {
                if (v[i] < bucket[j].first)
                {
                    bucket.insert(bucket.begin() + j, {v[i], 1});
                    bucket.pop_back();
                    break;
                }
                else if (v[i] == bucket[j].first)
                {
                    bucket[j].second++;
                    break;
                }
            }
        }

        bucket.assign(3, {0, 0});
        for (int i = n; i >= 1; i--)
        {
            if (v[i] == -1) continue;
            for (auto [val, c] : bucket)
            {
                if (val - v[i] >= tar)
                {
                    R[i] += c;
                }
            }

            for (int j = 0; j < 3; j++)
            {
                if (v[i] > bucket[j].first)
                {
                    bucket.insert(bucket.begin() + j, {v[i], 1});
                    bucket.pop_back();
                    break;
                }
                else if (v[i] == bucket[j].first)
                {
                    bucket[j].second++;
                    break;
                }
            }
        }

        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++)
        {
            res[i] = L[i] + R[i];
        }

        return res;
    };

    auto check = [&](i64 tar)
    {
        auto res = calc(tar);
        int mx = *max_element(res.begin(), res.end());
        if (mx <= 1) return true;

        vector<int> cand;
        if (mx > 2)
        {
            for (int i = 1; i <= n; i++)
            {
                if (res[i] > 2)
                {
                    cand.push_back(i);
                    break;
                }
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (res[i] != 2) continue;
                for (int j = 1; j <= n; j++)
                {
                    if (i == j) cand.push_back(j);
                    else if (j < i && a[i] - a[j] >= tar) cand.push_back(j);
                    else if (j > i && a[j] - a[i] >= tar) cand.push_back(j);
                }
                break;
            }
        }

        for (auto idx : cand)
        {
            v[idx] = -1;
            auto res1 = calc(tar);
            v[idx] = a[idx];
            if (*max_element(res1.begin(), res1.end()) <= 1) return true;
        }

        return false;
    };

    i64 l = -1e10, r = 1e10;
    // i64 l = 0, r = 1;
    while (l < r)
    {
        i64 mid = l + r + 1 >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid;
    }

    cout << l << "\n";
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
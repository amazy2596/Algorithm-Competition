// Problem: F1. From the Unknown (Easy Version)
// URL: https://codeforces.com/contest/2136/problem/F1
// Author: amazy
// Date: 2025-08-29 01:06:59

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
    auto query = [&](vector<int> v)
    {
        cout << "? " << v.size() << " ";
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;

        int res;
        cin >> res;

        return res;
    };

    const int N = 1e5;
    vector<int> tmp(N);
    fill(tmp.begin(), tmp.end(), 1);
    int l1 = query(tmp);
    int L = (N + l1 - 1) / l1;
    int R = (l1 == 1 ? N : (N - 1) / (l1 - 1));

    if (L == R)
    {
        cout << "! " << L << endl;
        return;
    }

    tmp.resize(0);
    for (int i = 1; i <= R - L; i++)
    {
        tmp.push_back(L);
        tmp.push_back(i);
    }

    int l2 = query(tmp);    
    cout << "! " << L + (2 * (R - L) - l2) << endl;
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
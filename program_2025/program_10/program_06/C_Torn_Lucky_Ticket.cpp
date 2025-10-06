// Problem: C. Torn Lucky Ticket
// URL: https://codeforces.com/problemset/problem/1895/C
// Author: amazy
// Date: 2025-10-06 17:10:27

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

    vector<string> a(n);
    map<int, map<int, int>> cnt1;
    map<int, map<int, map<int, int>>> cnt2;
    for (auto &s : a)
    {
        cin >> s;
        int sum = 0;
        for (int j = 0; j < s.length(); j++)
            sum += s[j] - '0';
        cnt1[s.length()][sum]++;

        int pre = 0;
        for (int d = 1; d <= s.length() / 2; d++)
        {
            pre += s[d - 1] - '0';
            cnt2[s.length()][d][sum - 2 * pre]++;
        }
    }

    i64 ans = 0;
    for (auto &s : a)
    {
        int len = s.length();
        int sum = 0;
        for (auto c : s) sum += c - '0';
        for (int j = 1; j <= 5; j++)
        {
            if ((j + len) % 2 != 0) continue;
            if (j <= len)
            {
                int k = (len + j) / 2;
                int pre = 0;
                for (int i = 0; i < k; i++)
                {
                    if (i < k) 
                        pre += s[i] - '0';
                }
                ans += cnt1[j][2 * pre - sum];
            }
            else 
            {
                int d = (j - s.length()) / 2;
                ans += cnt2[j][d][sum];
            }
        }
    }

    cout << ans << "\n";
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
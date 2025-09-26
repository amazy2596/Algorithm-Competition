// Problem: 重组猎魔团试炼
// URL: https://ac.nowcoder.com/acm/contest/117762/C
// Author: amazy
// Date: 2025-09-26 19:34:34

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
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            cout << "0\n";
            return;
        }
    }

    int ans = inf;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> tmp;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                tmp.push_back(s[i] - '0');
            }
        }

        vector<int> p(tmp.size());
        iota(p.begin(), p.end(), 0);
        do
        {
            int num = 0;
            for (int i = 0; i < p.size(); i++)
                num = (num * 10 + tmp[p[i]]);

            if (num != 0 && num % d == 0)
                ans = min(ans, num);
        } while (next_permutation(p.begin(), p.end()));
    }

    if (ans == inf) cout << "-1\n";
    else cout << ans << "\n";
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
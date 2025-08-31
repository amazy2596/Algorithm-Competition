// Problem: I Wanna Make It Palindromic
// URL: https://ac.nowcoder.com/acm/contest/115999/B
// Author: amazy
// Date: 2025-08-31 22:32:40

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
    vector<int> a(n + 1), b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += 200;
        b.push_back(a[i]);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    vector<int> tot(405);
    vector<vector<int>> cnt(405, vector<int>(405));
    int P = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        int j = n - i + 1;
        if (a[i] == a[j])
            continue;
        tot[a[i]]++;
        tot[a[j]]++;
        P++;
        int x = min(a[i], a[j]), y = max(a[i], a[j]);
        cnt[x][y]++;
    }

    int ans = inf;
    for (auto p1 : b)
    {
        for (auto p2 : b)
        {
            int tmp;
            if (p1 == p2)
                tmp = tot[p1];
            else 
                tmp = tot[p1] + tot[p2] - cnt[min(p1, p2)][max(p1, p2)];
            ans = min(ans, tmp + 2 * (P - tmp));
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
// Problem: F. Twin Polynomials
// URL: https://codeforces.com/contest/2160/problem/F
// Author: amazy
// Date: 2025-10-28 22:18:49

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

struct DSU
{
    vector<int> f, siz;

    DSU(int n) : f(n), siz(n, 1)
    {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x)
    {
        while (f[x] != x)
            x = f[x] = f[f[x]];
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (siz[x] < siz[y])
            swap(x, y);

        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

const int N = 4e5 + 5;
i64 dp[N];

void init()
{
    dp[0] = 1, dp[1] = 2;
    for (int i = 2; i < N; i++)
    {
        dp[i] = 2 * dp[i - 1] + (i - 1) * dp[i - 2];
        dp[i] %= mod;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    DSU dsu(n + 1);
    for (int i = 0; i <= n; i++) cin >> a[i];

    for (int i = 0; i <= n; i++)
    {
        if (a[i] != -1 && a[i] != 0)
        {
            dsu.merge(i, a[i]);
            if (a[a[i]] == -1) a[a[i]] = i;
            else if (a[a[i]] != i) 
            {
                cout << "0\n";
                return;
            }
        }
    }

    int m = 0;
    for (int i = 0; i <= n; i++)
    {
        if (a[i] == -1 && i != 0) m++;
        if (dsu.size(i) > 2)
        {
            cout << "0\n";
            return;
        }
    }

    if (dsu.size(n) == 1) cout << ((dp[m] - dp[m - 1]) % mod + mod) % mod << "\n";
    else cout << dp[m] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
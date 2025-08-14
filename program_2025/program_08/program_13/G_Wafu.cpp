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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int N = 40;
    vector<i64> p(N + 1), fact(N + 1, 1), pre(N + 1, 1);
    for (int i = 1; i <= N; i++)
    {
        p[i] = (1LL << i) - 1;
        fact[i] = (pre[i - 1] * i) % mod;
        pre[i] = (pre[i - 1] * fact[i]) % mod;
    }

    i64 ans = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (k <= 0)
            break;

        int x = a[i];
        do 
        {
            k--;
            ans = (ans * x) % mod;
            auto it = upper_bound(p.begin(), p.begin() + min(a[i], N), k);
            it--;

            int idx = it - p.begin();
            k -= p[idx];
            ans = (ans * pre[idx]) % mod;
            if (idx + 1 < x)
                x = idx + 1;
            else 
                break;
        } while (k > 0);
    }

    cout << ans % mod << "\n";
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
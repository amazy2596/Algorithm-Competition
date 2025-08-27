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
    i64 n, S; 
    cin >> n >> S;

    const int D = 10;                       
    vector<i64> p10(D + 1, 1);       
    for (int i = 1; i <= D; ++i) p10[i] = p10[i - 1] * 10;

    if (S < n) 
    {                       
        cout << -1 << "\n";
        return;
    }

    vector<i64> a(n, 1);
    i64 rem = S - n;
    vector<i64> cnt(2 * D, 0);

    cnt[0] = min(n, rem / 3);
    rem -= cnt[0] * 3;

    cnt[1] = min(cnt[0], rem / 4);
    rem -= cnt[1] * 4;

    for (int p = 1; p <= 9; ++p) 
    {
        i64 c = 4 * p10[p];
        cnt[2 * p] = min(n, rem / c);
        rem -= cnt[2 * p] * c;
        cnt[2 * p + 1] = min(cnt[2 * p], rem / c);
        rem -= cnt[2 * p + 1] * c;
    }

    for (i64 i = 0; i < cnt[0]; ++i) a[i] += 3; 
    for (i64 i = 0; i < cnt[1]; ++i) a[i] += 4;
    for (int p = 1; p <= 9; ++p) 
    {
        i64 add = 4 * p10[p];
        for (i64 i = 0; i < cnt[2 * p]; ++i) 
            a[i] += add;   
        for (i64 i = 0; i < cnt[2 * p + 1]; ++i) 
            a[i] += add;
    }

    for (int i = 0; i < n; ++i) 
        cout << a[i] << " \n"[i == n - 1];
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
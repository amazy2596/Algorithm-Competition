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
    i64 sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    
    vector<i64> ans = a;
    i64 base = 499999;
    i64 diff = 0;
    if (sum < 100)
    {
        diff = (100 - sum) * 1e6;
        for (int i = 1; i <= n; i++)
        {
            if (diff >= base)
            {
                ans[i] = a[i] * 1e6 + base;
                diff -= base;
            }
            else 
            {
                ans[i] = a[i] * 1e6 + diff;
                diff = 0;
            }
        }
    }
    else if (sum > 100)
    {
        diff = (sum - 100) * 10;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0) continue;
            if (diff >= 5)
            {
                ans[i] = a[i] * 10 - 5;
                diff -= 5;
            }
            else 
            {
                ans[i] = a[i] * 10 - diff;
                diff = 0;
            }
        }
    }

    if (diff != 0)
    {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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
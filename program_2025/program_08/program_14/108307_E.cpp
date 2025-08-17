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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (m == 1)
    {
        int ans = 0, pre = a[1];
        for (int i = 2; i <= n; i++)
        {
            ans += abs(pre - a[i]);
            pre = max(pre, a[i]);
        }

        cout << ans << "\n";
    }
    else 
    {
        int ans = inf;
        for (int mid = 1; mid <= n; mid++)
        {
            int sum = 0;
            int cnt = 0, pre = a[1];
            for (int i = 2; i <= mid; i++)
            {
                cnt += abs(pre - a[i]);
                pre = max(pre, a[i]);
            }
            sum += cnt;
            
            if (mid == n)
            {
                ans = min(ans, sum);
                continue;
            }

            cnt = 0, pre = a[mid + 1];
            for (int i = mid + 2; i <= n; i++)
            {
                cnt += abs(pre - a[i]);
                pre = max(pre, a[i]);
            }
            sum += cnt;

            ans = min(ans, sum);
        }

        cout << ans << "\n";
    }

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
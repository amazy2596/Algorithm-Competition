#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    int ans = 0;
    if (x > y)
    {
        if (k >= b)
        {
            int cnt = (k - b) / y + 1;
            ans += cnt;
            k -= cnt * y;
        }

        if (k >= a)
        {
            int cnt = (k - a) / x + 1;
            ans += cnt;
            k -= cnt * x;
        }
    }
    else 
    {        
        if (k >= a)
        {
            int cnt = (k - a) / x + 1;
            ans += cnt;
            k -= cnt * x;
        }

        if (k >= b)
        {
            int cnt = (k - b) / y + 1;
            ans += cnt;
            k -= cnt * y;
        }
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
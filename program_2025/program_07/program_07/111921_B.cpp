#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = inf;
    vector<int> a(n + 1), odd(n + 1), even(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] & 1)
        {
            odd[i] = even[i - 1];
            even[i] = 1 + odd[i - 1];
        }
        else 
        {
            odd[i] = 1 + even[i - 1];
            even[i] = odd[i - 1];
        }

        if (i >= m)
        {
            int l = i - m, r = i;
            if (m & 1)
                ans = min({ans, odd[r] - even[l], even[r] - odd[l]});
            else 
                ans = min({ans, odd[r] - odd[l], even[r] - even[l]});
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
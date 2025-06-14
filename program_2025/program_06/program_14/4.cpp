#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct node
{
    int v, w, s;
};

void solve()
{
    int n, v;
    cin >> n >> v;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].v >> a[i].w >> a[i].s;

    vector<int> dp(v + 1, -inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= a[i].v; j--)
        {
            for (int k = 0; k * a[i].v <= j && k <= a[i].s; k++)
            {
                dp[j] = max(dp[j], dp[j - k * a[i].v] + k * a[i].w);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
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
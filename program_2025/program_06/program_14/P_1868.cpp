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
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), [&](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });

    const int N = 3e6 + 5;
    vector<int> dp(n + 1, -inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1]);
        int pos = upper_bound(a.begin() + 1, a.begin() + i, a[i].first - 1, [](int val, pair<int, int> p){
            return val < p.second;
        }) - a.begin() - 1;
        dp[i] = max(dp[i], dp[pos] + a[i].second - a[i].first + 1);
    }

    cout << dp[n] << "\n";
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
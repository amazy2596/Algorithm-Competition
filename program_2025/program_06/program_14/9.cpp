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
    int n, V;
    cin >> n >> V;
    
    vector<int> dp(V + 1, -inf), pre_dp;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;

        pre_dp = dp;
        while (s--)
        {
            int v, w;
            cin >> v >> w;
            
            for (int j = V; j >= v; j--)
            {
                dp[j] = max(dp[j], pre_dp[j - v] + w);
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
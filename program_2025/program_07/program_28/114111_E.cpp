#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

vector<int> dp(2e5 + 5, inf);
void init()
{
    dp[0] = 0;
    for (int i = 1; i <= 2e5 + 5; i++)
    {
        for (int j = 1; j * (j + 1) / 2 <= 2e5 + 5; j++)
        {
            int w = j * (j + 1) / 2;
            if (i >= w && dp[i - w] != inf)
            {
                if (dp[i - w] == 0)
                    dp[i] = min(dp[i], dp[i - w] + j);
                else 
                    dp[i] = min(dp[i], dp[i - w] + j + 1);
            } 
        }
    }
}

void solve()
{
    int k;
    cin >> k;
    
    cout << dp[k] << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
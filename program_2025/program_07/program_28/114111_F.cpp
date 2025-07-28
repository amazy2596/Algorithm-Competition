#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

vector<int> dp(2e5 + 5, inf), convert(2e5 + 5);
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
                if (dp[i - w] == 0 && dp[i - w] + j < dp[i])
                {
                    dp[i] = dp[i - w] + j;
                    convert[i] = j;
                }
                else if (dp[i - w] + j + 1 < dp[i])
                {
                    dp[i] = min(dp[i], dp[i - w] + j + 1);
                    convert[i] = j;
                }
            } 
        }
    }
}

void solve()
{
    int k;
    cin >> k;

    string ans;
    while (k)
    {
        int j = convert[k];
        int w = j * (j + 1) / 2;
        ans += string(j, '1');
        ans += "0";
        k -= w;
    }

    ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
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
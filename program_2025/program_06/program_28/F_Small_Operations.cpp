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
    int x, y, k;
    cin >> x >> y >> k;

    int g = __gcd(x, y);

    auto get = [&](int x)
    {
        vector<int> fac;
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                fac.push_back(i);
                fac.push_back(x / i);
            }
        }

        sort(fac.begin(), fac.end());
        fac.erase(unique(fac.begin(), fac.end()), fac.end());
        vector<int> dp(fac.size(), inf);
        dp[0] = 0;
        for (int i = 1; i < fac.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (fac[i] / fac[j] <= k && fac[i] % fac[j] == 0)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }

        return dp.back();
    };

    int ans = get(x / g) + get(y / g);

    cout << (ans >= inf ? -1 : ans) << "\n";
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
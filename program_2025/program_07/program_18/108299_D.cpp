#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

void solve()
{
    int n, V;
    cin >> n >> V;

    map<int, vector<pair<int, int>>> group;
    for (int i = 1; i <= n; i++)
    {
        int h, s, d;
        cin >> h >> s >> d;
        group[s].emplace_back(h, d);
    }

    int ans = 0;
    for (int total = 1; total <= V; total++)
    {
        vector<int> dp(total + 1, -inf);
        dp[0] = 0;

        for (auto &[s, vec] : group)
        {
            if (s > total)
                break;

            vector<int> a;
            for (auto [h, d] : vec)
                a.push_back(h - (V - total) * d);

            int k_max = total / s;
            if (a.size() > k_max)
            {
                partial_sort(a.begin(), a.begin() + k_max, a.end(), greater<int>());
                a.resize(k_max);
            }
            else 
                sort(a.rbegin(), a.rend());
            
            vector<int> pre(a.size() + 1);
            for (int i = 0; i < a.size(); i++)
                pre[i + 1] = pre[i] + a[i];

            for (int j = total; j >= 0; j--)
            {
                for (int k = 1; k < pre.size(); k++)
                {
                    if (j >= k * s)
                        dp[j] = max(dp[j], dp[j - k * s] + pre[k]);
                    else 
                        break;
                }
            }
        }

        ans = max(ans, dp[total]);
    }

    cout << ans << "\n";
}

signed main()
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
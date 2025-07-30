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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int bits = 30;
    vector<vector<vector<int>>> count(bits, vector<vector<int>>(2, vector<int>(2, 0)));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int pre_1 = 0;
        if ((a[i] & 1) == 1)
        {
            ans += count[0][0][0] + count[0][0][1];
            pre_1++;
            count[0][1][pre_1 % 2]++;
        }
        else 
        {
            ans += count[0][1][0] + count[0][1][1];
            count[0][0][pre_1 % 2]++;
        }
        
        for (int k = 1; k < bits; k++)
        {
            if ((a[i] >> k) & 1)
            {
                int tmp = count[k][0][pre_1 % 2];

                ans += (1ll << k) * tmp;

                pre_1++;
                count[k][1][pre_1 % 2]++;
            }   
            else 
            {
                int tmp = count[k][1][(pre_1 % 2) ^ 1];

                ans += (1ll << k) * tmp;

                count[k][0][pre_1 % 2]++;
            }
        }
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
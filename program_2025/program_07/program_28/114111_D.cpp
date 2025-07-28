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
    string s;
    cin >> s;
    s = " " + s;

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (s[i] == '1');

    int ans = inf;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                int tmp1 = (i - 1 - pre[i - 1]) + (pre[j - 1] - pre[i - 1]) + (k - j - (pre[k - 1] - pre[j - 1])) + (pre[n] - pre[k - 1]);
                int tmp2 = (pre[i - 1]) + (j - i - (pre[j - 1] - pre[i - 1])) + (pre[k - 1] - pre[j - 1]) + (n - k + 1 - (pre[n] - pre[k - 1]));

                ans = min({ans, tmp1, tmp2});
            }
        }
    }

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
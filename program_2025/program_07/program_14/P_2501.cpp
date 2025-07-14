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
    int n;
    cin >> n;
    vector<int> a(n + 2), b(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i] - i;

    vector<int> val, f(n + 2);
    vector<vector<int>> vec(n + 2);
    for (int i = 1; i <= n; i++)
    {
        // if (j < i)
        // a[i] - a[j] >= i - j;
        // a[i] - i >= a[j] - j;
        auto it = upper_bound(val.begin(), val.end(), b[i]);
        int idx = it - val.begin();
        if (idx == val.size())
            val.push_back(b[i]);
        else 
            val[idx] = b[i];
        f[i] = idx + 1;
        vec[f[i]].push_back(i);
    }

    b[0] = -inf, b[n + 1] = inf;
    vec[0].push_back(0);
    f[n + 1] = val.size() + 1;
    vec[f[n + 1]].push_back(n + 1);

    int cnt = n - val.size();
    cout << cnt << "\n";

    vector<int> dp(n + 2, inf), pre(n + 2), suf(n + 2);
    dp[0] = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j : vec[f[i] - 1])
        {
            if (j >= i || b[j] > b[i])
                continue;

            pre[j] = 0;
            for (int k = j + 1; k < i; k++)
                pre[k] = pre[k - 1] + abs(b[k] - b[j]);
            suf[i] = 0;
            for (int k = i - 1; k > j; k--)
                suf[k] = suf[k + 1] + abs(b[k] - b[i]);

            for (int k = j; k < i; k++)
            {
                int cost = pre[k] + suf[k + 1];
                dp[i] = min(dp[i], dp[j] + cost);
            }
        }
    }

    cout << dp[n + 1] << "\n";

    // int mx = 2e5 + 5;
    // vector<pair<int, int>> prev(mx, {0, 0}), cur(mx, {inf, inf});

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < mx; j++)
    //         cur[j] = {inf, inf};

    //     auto pre = make_pair(inf, inf);
    //     for (int j = 0; j < mx; j++)
    //     {
    //         cur[j] = min(cur[j], make_pair(pre.first + (a[i] != j), pre.second + abs(a[i] - j)));
    //         pre = min(pre, prev[j]);
    //     }

    //     swap(prev, cur);
    // }
    // auto [cnt, sum] = *min_element(prev.begin(), prev.end(), [](const pair<int, int> &a, const pair<int, int> &b){
    //     if (a.first == b.first)
    //         return a.second < b.second;
    //     return a.first < b.first;
    // });
    // cout << cnt << "\n" << sum << "\n";
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
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j <= 63; j++)
        {
            if (((a[i] >> j) & 1) == 0)
            {
                q.push({1ll << j, a[i]});
                break;
            }
        }
    }

    while (k > 0)
    {
        auto [add, x] = q.top();

        if (k < add)
            break;

        q.pop();
        x += add;
        k -= add;
        for (int j = 0; j <= 63; j++)
        {
            if (((x >> j) & 1) == 0)
            {
                q.push({1ll << j, x});
                break;
            }
        }
    }

    int ans = 0;
    while (!q.empty())
    {
        auto [add, x] = q.top();
        q.pop();

        for (int i = 0; i <= 63; i++)
            ans += (x >> i) & 1;
    }

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
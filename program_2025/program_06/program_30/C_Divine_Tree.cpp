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
    int n, m;
    cin >> n >> m;
    if (m < n || m > n * (n + 1) / 2)
    {
        cout << "-1\n";
        return;
    }

    int k = n;
    while (k >= 1)
    {
        if (k + n - 1 <= m)
            break;
        k--;
    }

    m -= k;
    vector<pair<int, int>> ans;
    vector<int> vis(n + 1);
    vis[k] = 1;
    int remain = n - 1;
    for (int i = n; i >= 1; i--)
    {
        if (vis[i])
            continue;
        if (remain == m)
        {
            if (k != 1)
                ans.push_back({k, 1});
            for (int j = 2; j <= n; j++)
            {
                if (!vis[j])
                {
                    ans.push_back({1, j});
                }
            }
            break;
        }
        else if (remain < m)
        {
            int x = m - remain + 1;
            if (1 <= x && x <= n && !vis[x])
            {
                vis[x] = 1;
                ans.push_back({k, x});
                if (k != 1)
                    ans.push_back({k, 1});
                for (int j = 2; j <= n; j++)
                {
                    if (!vis[j])
                    {
                        ans.push_back({1, j});
                    }
                }
                break;
            }
            else 
            {
                ans.push_back({k, i});
                remain--;
                m -= i;
            }
        }
        vis[i] = 1;
    }

    cout << k << "\n";
    for (auto [u, v] : ans)
        cout << u << " " << v << "\n";
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
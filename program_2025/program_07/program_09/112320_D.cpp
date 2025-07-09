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

    vector<vector<int>> ans;
    vector<int> cur;
    int sum = 0;
    auto dfs = [&](auto dfs) -> void
    {
        if (sum == n)
        {
            ans.push_back(cur);
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!cur.empty() && i == cur.back())
                continue;
            if (i + sum > n)
                break;
                
            cur.push_back(i);
            sum += i;
            dfs(dfs);
            cur.pop_back();
            sum -= i;
        }
    };

    dfs(dfs);

    sort(ans.begin(), ans.end());
    for (auto &v : ans)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " \n"[i == v.size() - 1];
        }
    }
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
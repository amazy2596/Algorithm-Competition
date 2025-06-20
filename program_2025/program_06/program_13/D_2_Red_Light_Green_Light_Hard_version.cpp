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
    vector<int> p(n), d(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> d[i];

    map<int, vector<pair<int, int>>> L, R;
    for (int i = 0; i < n; i++)
    {
        int x = ((p[i] - d[i]) % k + k) % k;
        int y = ((p[i] + d[i]) % k + k) % k;
        L[y].push_back({p[i], i});
        R[x].push_back({p[i], i});
    }

    for (auto &[_, v] : L)
        sort(v.begin(), v.end());
    for (auto &[_, v] : R)
        sort(v.begin(), v.end());

    vector<array<pair<int, int>, 2>> nex(n);
    for (int i = 0; i < n; i++)
    {
        int remain_r = ((p[i] - d[i]) % k + k) % k;
        auto it_r = upper_bound(R[remain_r].begin(), R[remain_r].end(), make_pair(p[i], inf));
        if (it_r == R[remain_r].end())
            nex[i][0] = {-1, -1};
        else 
            nex[i][0] = {it_r->second, 1};

        int remain_l = (p[i] + d[i] + k) % k;
        auto it_l = lower_bound(L[remain_l].begin(), L[remain_l].end(), make_pair(p[i], -1ll));
        if (it_l == L[remain_l].begin())
            nex[i][1] = {-1, -1};
        else 
            nex[i][1] = {(--it_l)->second, 0};
    }

    vector<array<int, 2>> state(n, {-1, -1});
    map<pair<int, int>, int> vis;
    auto dfs = [&](auto dfs, int i, int dir) -> bool
    {
        vis[{i, dir}] = 1;

        int can = 1;
        auto [ni, ndir] = nex[i][dir];

        if (ni == -1)
            can = 1;
        else 
        {
            if (vis[{ni, ndir}] == 1)
                can = 0;
            else if (vis[{ni, ndir}] == 2)
                can = state[ni][ndir];
            else 
                can = dfs(dfs, ni, ndir);
        }

        vis[{i, dir}] = 2;
        state[i][dir] = can;
        return can;
    };

    for (int i = 0; i < n; i++)
    {
        for (int dir = 0; dir < 2; dir++)
        {
            if (!vis[{i, dir}])
            {
                dfs(dfs, i, dir);
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;

        int rem = a % k;
        auto it = lower_bound(R[rem].begin(), R[rem].end(), make_pair(a, -1ll));
        if (it == R[rem].end())
        {
            cout << "YES\n";
            continue;
        }

        auto [p, idx] = *it;
        cout << (state[idx][1] ? "YES\n" : "NO\n");
    }
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
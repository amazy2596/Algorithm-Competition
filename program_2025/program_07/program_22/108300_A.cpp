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
    vector<pair<int, int>> a(n + 1);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        p[i] = a[i].first;
    }
    
    sort(a.begin() + 1, a.end());
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    for (int k = 1; k <= n; k++)
    {
        auto [f, idx] = a[k];
        if (f == 1)
            continue;
        g[idx][idx] = 1;
        int id = 2;
        for (int i = 1; i <= n; i++)
        {
            if (g[i][idx] == 0 && i != idx && p[i] != id && id < f)
                g[i][idx] = id++;
        }
        id = 2;
        for (int j = 1; j <= n; j++)
        {
            if (g[idx][j] == 0 && j != idx && p[j] != id && id < f)
                g[idx][j] = id++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << g[i][j] << " ";
        }

        cout << "\n";
    }
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
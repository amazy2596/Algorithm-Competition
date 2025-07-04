#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int N = 2e5 + 5;
vector<int> d[N];
void init()
{
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            d[j].push_back(i);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> f(n + 1), g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int mx = 0;
        for (auto x : d[a[i]])
            mx = max(mx, f[x] + 1);
        f[a[i]] = max(mx, g[a[i]]);
        for (auto x : d[a[i]])
            g[x] = max(g[x], f[a[i]] + 1);
    }

    int ans = *max_element(f.begin(), f.end());
    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct DSU
{
    vector<int> f, siz;

    DSU(int _n) : f(_n + 1), siz(_n + 1, 1)
    {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x)
    {
        while (x != f[x])
            x = f[x] = f[f[x]];
        return x;
    }

    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        
        f[y] = x;
        siz[x] += siz[y];
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](auto i, auto j){
        return a[i] > a[j];
    });

    DSU fl(n + 1), fr(n + 1);
    int mn = inf;
    int ans = 0;
    for (auto i : p)
    {
        for (int j = 0; j < 2; j++)
        {
            int x = fl.find(i + 1); 
            if (x)
            {
                fl.merge(x - 1, x);
                mn = min(mn, a[x - 1]);
            }

            x = fr.find(i);
            if (x < n)
            {
                fr.merge(x + 1, x);
                mn = min(mn, a[x]);
            }
        }

        ans = max(ans, a[i] - mn);
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
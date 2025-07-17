#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct node
{
    int l, r, real;

    bool operator<(node o)
    {
        if (l == o.l && r == o.r)
            return real < o.real;
        else if (l == o.l)
            return r < o.r;
        return l < o.l;
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<node> a(n);
    for (auto &[l, r, real] : a)
        cin >> l >> r >> real;

    sort(a.begin(), a.end());

    for (auto [l, r, real] : a)
    {
        if (l <= k && k <= r)
            k = max(k, real);
    }

    cout << k << "\n";
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
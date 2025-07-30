#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-9;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, L;
    cin >> n >> L;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    auto check = [&](double x)
    {
        vector<double> b(n + 1);
        vector<double> pre(n + 1);
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i] - x;
            pre[i] = pre[i - 1] + b[i];
        }

        double mn = inf;
        for (int i = L; i <= n; i++)
        {
            mn = min(mn, pre[i - L]);
            if (pre[i] - mn >= 0)
            {
                return true;
            }
        }

        return false;
    };
    
    double l = -1e4, r = 1e4;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else 
            r = mid;
    }

    cout << fixed << setprecision(5) << (r + l) / 2 << "\n";
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
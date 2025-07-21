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

    long double ans = 0;
    vector<pair<long double, long double>> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;

        if (i)
        {
            auto [x1, y1] = p[i - 1];
            auto [x2, y2] = p[i];
            long double e = sqrtl((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            long double tmp = inf;
            auto f = [&](long double k)
            {
                return 2 * k + (2 * e) / powl(2, k);
            };

            long double l = 0, r = 60;
            while (r - l > eps)
            {
                long double m1 = l + (r - l) / 3.0l;
                long double m2 = r - (r - l) / 3.0l;

                long double left = f(m1);
                long double right = f(m2);

                if (left < right)
                    r = m2;
                else 
                    l = m1;
            }

            ans += f((r + l) / 2l);
        }
    }

    cout << fixed << setprecision(9) << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
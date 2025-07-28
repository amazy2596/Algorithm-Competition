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
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int L, R;
    auto check = [&](int v)
    {
        vector<int> b(n + 1), pre(n + 1), premn(n + 1), preid(n + 1);
        int idx = 0;
        for (int i = 1; i <= n; i++)
        {
            b[i] = (a[i] >= v ? 1 : -1);
            pre[i] = pre[i - 1] + b[i];

            if (pre[i] < premn[i - 1])
                idx = i;

            premn[i] = min(premn[i - 1], pre[i]);
            preid[i] = idx;
        }

        for (int i = k; i <= n; i++)
        {
            if (pre[i] - premn[i - k] >= 0)
            {
                L = preid[i - k] + 1;
                R = i;
                return true;
            }
        }

        return false;
    };

    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    check(l);

    cout << l << " " << L << " " << R << "\n";
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
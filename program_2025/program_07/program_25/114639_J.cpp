#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int idx = n, mx = 0;
    for (int i = n; i >= 2; i--)
    {
        if (a[i] > mx)
        {
            idx = i;
            mx = a[i];
        }
    }

    if (mx == 0)
    {
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        return;
    }

    a[1] += a[idx];
    cout << n - 1 << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (i != idx)
        {
            cout << a[i] << ' ';
        }
    }
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
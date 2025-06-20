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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int x, y;
    bool ok = 1;
    if ((n * a[n] - a[1]) % (n * n - 1) == 0)
        x = (n * a[n] - a[1]) / (n * n - 1);
    else 
        ok = 0;

    if ((n * a[1] - a[n]) % (n * n - 1) == 0)
        y = (n * a[1] - a[n]) / (n * n - 1);
    else 
        ok = 0;

    for (int i = 1; i <= n; i++)
    {
        a[i] -= x * i + y * (n - i + 1);
        if (a[i] != 0)
        {
            ok = 0;
            break;
        }
    }

    if (x >= 0 && y >= 0 && ok)
        cout << "YES\n";
    else 
        cout << "NO\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
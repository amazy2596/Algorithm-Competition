#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n + 1);
    bool ok = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (i >= 2 && b[i] % b[i - 1] != 0)
            ok = 0;
    }

    int ans = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        if (b[i + 1] % b[i] != 0)
        {
            int g = __gcd(b[i], b[i + 1]);
            ans = lcm(ans, b[i] / g);
        }
    }

    cout << ans << "\n";
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
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



void solve()
{
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;
    if (sum % 2 == 1)
    {
        cout << "-1\n";
        return;
    }

    int half = sum / 2;
    vector<int> vis(n + 1);
    for (int i = n; i >= 1; i--)
    {
        if (half - i >= 0)
        {
            vis[i] = 1;
            half -= i;
            cout << i << " ";
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            cout << i << " ";
    }
    cout << "\n";
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
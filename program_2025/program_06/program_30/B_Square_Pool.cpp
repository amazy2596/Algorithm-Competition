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
    int n, s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;
        if (x == y && s % 2 == 0 && x == s / 2)
            ans++;
        else if (x == y)
        {
            if ((dx == 1 && dy == 1) || (dx == -1 && dy == -1))
                ans++;
        }
        else if (x + y == s)
        {
            if ((dx == 1 && dy == -1) || (dx == -1 && dy == 1))
                ans++;
        }
    }

    cout << ans << "\n";
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
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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a == b)
        cout << "0\n";
    else if (a > b)
    {
        if ((a ^ 1) != b)
            cout << "-1\n";
        else 
            cout << y << "\n";
    }
    else 
    {
        int ans = 0;
        while (a < b)
        {
            if ((a & 1) == 0)
                ans += min(x, y), a++;
            else 
                ans += x, a++;
        }

        cout << ans << "\n";
    }
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
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
    int n = 5;
    vector<int> a(n);
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != 0)
            y++;
    }

    int k;
    cin >> k;

    if (y == 0)
    {
        cout << 1 << "/" << 1000 << "\n";
        return;
    }
    else 
    {
        int x = 0;
        for (int i = 0; i < n; i++)
            x += (a[i] == k);

        if (x == 0)
        {
            cout << 0 << "/" << 1 << "\n";
            return;
        }

        int g = __gcd(x, y);
        x /= g;
        y /= g;
        cout << x << "/" << y << "\n";
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
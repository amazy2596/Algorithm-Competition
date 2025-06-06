#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    vector g(n, vector<int>(n, -1));

    int cnt = 0, step = 1, count = 0;
    int x = (n + 1) / 2 - 1, y = (n + 1) / 2 - 1, k = 0;
    while (cnt < n * n)
    {
        for (int j = 0; j < step && cnt < n * n; j++)
        {
            g[x][y] = cnt++;
            auto [dx, dy] = dir4[k];
            x += dx, y += dy;
        }
        k = (k + 1) % 4;
        count++;
        if (count == 2)
        {
            step++;
            count = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init()
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
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
    
    vector<int> vis(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (vis[i] || vis[j])
                continue;
            if ((i + j) % 4 == 3)
            {
                vis[i] = 1;
                vis[j] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cout << "Alice\n";
            return;
        }
    }

    cout << "Bob\n";
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
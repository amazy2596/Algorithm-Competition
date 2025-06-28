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
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];

    vector<int> f(15);
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= 10; i++)   
        f[i] = f[i - 1] + f[i - 2];

    for (int i = 0; i < m; i++)
    {
        int ok = 0;
        for (int j = 0; j < 3; j++)
        {
            if (f[n] + f[n - 1] <= a[i][j])
            {
                int can = 1;
                for (int k = 0; k < 3; k++)
                {
                    if (j == k)
                        continue;
                    if (a[i][k] < f[n])
                        can = 0;
                }

                if (can)
                    ok = 1;
            }
        }

        if (ok) cout << "1";
        else cout << "0";
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
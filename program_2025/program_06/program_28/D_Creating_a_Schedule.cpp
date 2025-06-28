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
    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        // a[i] /= 100;
    }
    sort(a.begin(), a.end());
    vector<array<int, 6>> ans(n);
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j % 2 == 0)
            {
                if (i < n / 2)
                    ans[i][j] = a[i];
                else 
                    ans[i][j] = a[m - (i - n / 2) - 1];
            }
            else 
            {
                if (i < n / 2)
                    ans[i][j] = a[m - i - 1];
                else 
                    ans[i][j] = a[i - n / 2];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << "\n";
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
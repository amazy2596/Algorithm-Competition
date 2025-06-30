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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // if (n == 2 && abs(a[0] - a[1]) > 1)
    // {
        // cout << "-1\n";
        // return;
    // }

    for (int i = 0; i < n - 1; i++)
    {
        if (abs(a[i] - a[i + 1]) <= 1)
        {
            cout << "0\n";
            return;
        }
    }

    int ans = inf;
    for (int i = 0; i < n - 1; i++)
    {
        int mx = max(a[i], a[i + 1]);
        int mn = min(a[i], a[i + 1]);
        for (int j = i - 1; j >= 0; j--)
        {
            if (mn - 1 <= a[j] && a[j] <= mx + 1)
            {
                ans = min(ans, i - j);
                break;
            }

            mx = max(mx, a[j]);
            mn = min(mn, a[j]);
        }

        mx = max(a[i], a[i + 1]);
        mn = min(a[i], a[i + 1]);
        for (int j = i + 2; j < n; j++)
        {
            if (mn - 1 <= a[j] && a[j] <= mx + 1)
            {
                ans = min(ans, j - i - 1);
                break;
            }

            mx = max(mx, a[j]);
            mn = min(mn, a[j]);
        }
    }

    cout << (ans == inf ? -1 : ans) << "\n";
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
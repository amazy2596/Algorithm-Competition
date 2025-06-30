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
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                ans.emplace_back(1, j);
            }

            if (b[j] > b[j + 1])
            {
                swap(b[j], b[j + 1]);
                ans.emplace_back(2, j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] > b[i])
        {
            swap(a[i], b[i]);
            ans.emplace_back(3, i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                ans.emplace_back(1, j);
            }

            if (b[j] > b[j + 1])
            {
                swap(b[j], b[j + 1]);
                ans.emplace_back(2, j);
            }
        }
    }

    // for (int i = 1; i <= n; i++)
        // cout << a[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++)
        // cout << b[i] << " \n"[i == n];

    cout << ans.size() << "\n";
    for (auto [op, i] : ans)
        cout << op << " " << i << "\n";
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
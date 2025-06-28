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
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    vector<pair<int, int>> seg(n);
    for (int i = 0; i < n; i++)
        cin >> seg[i].first >> seg[i].second;

    int h = 0;
    vector<int> last;
    for (int i = 0; i < n; i++)
    {
        auto [low, high] = seg[i];

        if (d[i] == 1)
            h++;
        else if (d[i] == -1)
            last.push_back(i);

        while (h < low)
        {
            if (last.empty())
            {
                cout << "-1\n";
                return;
            }

            d[last.back()] = 1;
            h++;
            last.pop_back();
        }

        while (h + last.size() > high)
        {
            if (last.empty())
            {
                cout << "-1\n";
                return;
            }

            d[last.back()] = 0;
            last.pop_back();
        }
    }

    for (int i = 0; i < n; i++)
        cout << max(0ll, d[i]) << " ";
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
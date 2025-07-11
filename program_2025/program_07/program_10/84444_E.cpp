#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-9;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), all;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        cin >> b[i], all.push_back(b[i]);

    int q;
    cin >> q;
    vector<int> k(q + 1);
    for (int i = 1; i <= q; i++)
        cin >> k[i], all.push_back(k[i]);

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    all.insert(all.begin(), 0ll);

    int m = all.size();
    map<int, int> day;
    for (int i = 1; i <= n; i++)
    {
        auto it = upper_bound(all.begin(), all.end(), b[i]);

        day[1] += a[i];
        day[it - all.begin()] -= a[i];
    }

    int sum = 0, pre = 0;
    unordered_map<int, int> mp;
    for (int i = 1; i < all.size(); i++)
    {
        pre += day[i];
        sum += pre * (all[i] - all[i - 1]);
        mp[all[i]] = sum;
    }

    for (int i = 1; i <= q; i++)
        cout << mp[k[i]] << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
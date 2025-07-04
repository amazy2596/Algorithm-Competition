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
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> a[i], mp[a[i]]++;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    if (a.size() == 1 && (2 * a[0] <= n || a[0] == n - 1))
        cout << "Other\n";
    else if (a.size() == 2)
    {
        int c0 = mp[a[0]], c1 = mp[a[1]];
        if ((c0 - 1 == a[0] && a[1] == c0) || (c1 - 1 == a[1] && a[0] == c1))
            cout << "Other\n";
        else 
            cout << "Lie\n";
    }
    else 
        cout << "Lie\n";
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
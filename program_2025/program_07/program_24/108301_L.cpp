#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<int> pre(n + 2), score(n + 2);
    int id = 1;
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        auto [key, val] = *it;
        pre[id] = pre[id - 1] + val;
        score[id] = key;
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        int tar = score[y] - x;

        if (tar <= 0)
        {
            cout << "0\n";
            continue;
        }

        
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
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
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    int sum = accumulate(a.begin() + 1, a.end(), 0);
    if (sum == 0)
    {
        cout << "-1\n";
        return;
    }
    else if (sum > s)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
        return;
    }

    int dis = s - sum;
    if (dis == 1)
    {
        int x = mp[0], y = mp[1], z = mp[2];
        while (x--)
            cout << "0 ";
        while (z--)
            cout << "2 ";
        while (y--)
            cout << "1 ";

        cout << "\n";
    }
    else 
    {
        cout << "-1\n";
    }

}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
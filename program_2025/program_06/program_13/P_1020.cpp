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
    int x;
    vector<int> a;
    while (cin >> x)
    {
        if (x == EOF)
            break;
        a.push_back(x);
    }

    vector<int> d1, d2;
    for (auto x : a)
    {
        int nx = -x;
        auto it1 = upper_bound(d1.begin(), d1.end(), nx);
        if (it1 == d1.end())
            d1.push_back(nx);
        else 
            *it1 = nx;

        auto it2 = lower_bound(d2.begin(), d2.end(), x);
        if (it2 == d2.end())
            d2.push_back(x);
        else 
            *it2 = x;
    }

    cout << d1.size() << "\n" << d2.size() << "\n";
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
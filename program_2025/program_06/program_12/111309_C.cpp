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
    int l, r;
    cin >> l >> r;
    if (l == r)
    {
        cout << "-1\n";
        return;
    }
    if (r - l + 1 == 2 && l != 1)
    {
        cout << "-1\n";
        return;
    }
    else if (r - l + 1 == 2 && l == 1)
    {
        cout << "0\n";
        return;
    }

    if ((r - l + 1) % 2 == 1)
        cout << "1\n";
    else 
        cout << "0\n";
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
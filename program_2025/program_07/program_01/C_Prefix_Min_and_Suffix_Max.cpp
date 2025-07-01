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
    vector<int> a(n + 1), pre(n + 1, inf), suf(n + 2, -inf);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
        
    for (int i = 1; i <= n; i++)
        pre[i] = min(pre[i - 1], a[i]);

    for (int i = n; i >= 1; i--)
        suf[i] = max(suf[i + 1], a[i]);

    for (int i = 1; i <= n; i++)
    {
        if (pre[i] < a[i] && suf[i] > a[i])
            cout << "0";
        else 
            cout << "1";
    }

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
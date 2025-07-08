#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    int last = 0;
    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '#')
            last = i;
        pre[i] = last;
    }

    last = n + 1;
    for (int i = n; i >= 1; i--)
    {
        if (s[i] == '#')
            last = i;
        suf[i] = last;
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        int l = suf[x], r = pre[y];
        if (l == n + 1 || r == 0 || l > r)
        {
            cout << "0\n";
            continue;
        }
        cout << r - l + 1 << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
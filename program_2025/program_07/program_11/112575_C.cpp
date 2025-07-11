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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a.push_back(a[i]);

    vector<deque<int>> pos(m);
    vector<int> idx(m);
    for (int i = 1; i <= n; i++)
        pos[a[i]].push_back(i);

    int num = 0;
    for (int i = 1; i < m; i++)
        num += (pos[i - 1].front() >= pos[i].front());

    int ans = 0;
    // ans += (num == 0);
    int l = 1, r = n;
    while (r <= 2 * n - 1)
    {
        int cur = a[l];
        if (cur > 0)
            num -= (pos[cur - 1].front() >= pos[cur].front());
        if (cur < m - 1)
            num -= (pos[cur].front() >= pos[cur + 1].front());

        pos[a[l]].pop_front();
        pos[a[r + 1]].push_back(r + 1);

        if (cur > 0)
            num += (pos[cur - 1].front() >= pos[cur].front());
        if (cur < m - 1)
            num += (pos[cur].front() >= pos[cur + 1].front());

        l++, r++;
        ans += (num == 0);
    }

    cout << ans << "\n";
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
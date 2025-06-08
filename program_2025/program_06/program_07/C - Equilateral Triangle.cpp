#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, l;
    cin >> n >> l;
    vector<int> d(n);
    for (int i = 0; i < n - 1; i++)
        cin >> d[i];

    if (l % 3 != 0)
    {
        cout << "0\n";
        return;
    }

    vector<int> point(l);
    int pos = 0;
    for (int i = 0; i < n - 1; i++)
    {
        point[pos]++;
        pos = (pos + d[i]) % l;
    }
    point[pos]++;

    int ans = 0;
    for (int i = 0; i < l / 3; i++)
    {
        ans += point[i] * point[i + l / 3] * point[i + 2 * l / 3];
    }

    cout << ans << "\n";
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
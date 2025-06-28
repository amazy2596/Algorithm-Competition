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
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int dn = max(n - a, a - 1);
    int dm = max(m - b, b - 1);

    vector<int> x = {n, m, n - dn, m - dm};
    vector<int> cnt(4, 0);
    for (int i = 0; i < 4; i++)
    {
        int temp = x[i];
        while (temp > 1)
        {
            if (temp % 2 == 1)
                temp = temp / 2 + 1;
            else 
                temp /= 2;
            cnt[i]++;
        }
    }

    int ans1 = cnt[0] + cnt[3] + 1;
    int ans2 = cnt[1] + cnt[2] + 1;
    cout << min(ans1, ans2) << "\n";
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
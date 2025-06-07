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
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(3);
    for (auto &[a, b] : v)
        cin >> a >> b;

    sort(v.begin(), v.end());

    int ans = 1e9;
    do 
    {
        int cur = n;
        for (int i = 0; i < 3; i++)
        {
            if (v[i].first <= cur)
                cur = max(0ll, cur - v[i].second);
        }
        ans = min(ans, cur);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init()
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
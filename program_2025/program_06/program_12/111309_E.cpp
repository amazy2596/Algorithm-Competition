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
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    if (s.size() == 1)
    {
        cout << "0\n";
        return;
    }

    int has = false;
    if (*s.begin() == 0)
        s.erase(s.begin()), has = 1;

    int x = s.size() + has;
    int sum = 0;
    int ans = 0;
    while (!s.empty())
    {
        int x = s.size() + (has ? 1 : 0);
        int val = *s.begin();

        int remaining_val = val - sum;
        
        if (remaining_val <= 0)
        {
            has = 1;
            s.erase(s.begin());
            continue;
        }

        int k = (remaining_val + x - 1) / x;

        ans += k;
        sum += k * x;

        has = 1;
        s.erase(s.begin());
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
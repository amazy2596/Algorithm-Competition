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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];

    if (k == 0)
    {
        cout << sum << "\n";
        return;
    }
    else if (k == 1)
    {
        cout << max(sum - a[1], sum - a[n]) << "\n";
        return;
    }

    auto check = [&](int mn)
    {
        int cur = 0, cnt = 0;
        for (int i = 2; i <= n - 1; i++)
        {
            cur += a[i];

            if (cur >= mn)
            {
                cur = 0;
                i++;
                cnt++;
            }
        }

        return cnt >= k - 1;
    };

    int l = 0, r = sum;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else 
            r = mid - 1;
    }

    cout << l << "\n";
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
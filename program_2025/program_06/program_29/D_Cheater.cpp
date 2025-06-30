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
    vector<int> a(n + 1), b(n + 1), pre(n + 1, inf), suf(n + 2, -inf);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++)
        pre[i] = min(pre[i - 1], a[i]);
    for (int i = n; i >= 1; i--)
        suf[i] = max(suf[i + 1], a[i]);

    auto check = [&](int k) -> bool
    {
        int mn = pre[k], mx = suf[k + 1];
        int swp = mn < mx;
        int idx = -1;
        int res = 0;
        for (int i = 1; i <= k && swp; i++)
        {
            if (a[i] == mn)
            {
                idx = i;
                break;
            }
        }

        int j = 1, cnt = 0;
        for (int i = 1; i <= k; i++)
        {
            int my_card;
            if (swp && i == idx)
                my_card = mx;
            else 
                my_card = a[i];

            while (j <= n && b[j] > my_card)
                j++, cnt++;

            cnt++;

            if (j > n || cnt > n)
                return false;
        }

        return true;
    };

    int l = 0, r = n;
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
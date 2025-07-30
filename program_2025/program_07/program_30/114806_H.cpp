#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    int l = 0, r = 1;
    while (l < r && r < n)
    {
        if (s[r] == s[r - 1] || (r - 2 >= l && s[r] == s[r - 2]))
        {
            ans = max(ans, r - l);
            while ((r - 1 >= l && s[r] == s[r - 1]) || (r - 2 >= l && s[r] == s[r - 2]))
                l++;
        }
        r++;
    }
    ans = max(ans, r - l);

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
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
    string s;
    cin >> s;
    int x;
    cin >> x;

    vector<int> cnt(26);
    int l = 0, r = 0;
    int ans = inf;
    int cur = 0;

    while (r < s.length())
    {
        for (int i = s[r] - 'a' + 1; i < 26; i++)
            cur += cnt[i];

        cnt[s[r] - 'a']++;
        ans = min(ans, abs(x - cur));

        while (l <= r && cur >= x)
        {
            for (int i = s[l] - 'a' - 1; i >= 0; i--)
                cur -= cnt[i];

            cnt[s[l] - 'a']--;
            l++;
            ans = min(ans, abs(x - cur));
        }
        r++;
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
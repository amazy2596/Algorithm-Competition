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
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    map<int, int> mp1, mp2;
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        if (i < n)
        {
            int j = i - 1;
            
        }

        if (i % 2 == 0)
        {
            if (mp2.find(a[i]) != mp2.end())
                ans = max(ans, i);
            if (mp1.find(b[i]) != mp1.end())
                ans = max(ans, i);

            mp1[a[i]]++;
            mp2[b[i]]++;
        }
        else 
        {
            if (mp2.find(b[i]) != mp2.end())
                ans = max(ans, i);
            if (mp1.find(a[i]) != mp1.end())
                ans = max(ans, i);

            mp1[b[i]]++;
            mp2[a[i]]++;
        }
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}
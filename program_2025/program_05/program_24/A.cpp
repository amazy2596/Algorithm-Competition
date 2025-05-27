#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    set<int> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s.insert(i);

    vector<pair<int, int>> ans;
    int cur = 0;
    int mn = *min_element(a.begin() + 1, a.end()), mx = *max_element(a.begin() + 1, a.end());
    for (int i = 0; i < mn; i++)
        ans.push_back({1, i}), cur++;
    while (mn < mx)
    {
        set<int> ns;
        for (auto i : s)
        {
            if (a[i] != mn)
            {
                ns.insert(i);
            }
        }

        s = move(ns);
        mn = 1e9;
        for (auto i : s)
        {
            ans.push_back({2, i});
            mn = min(mn, a[i]);
        }
        cur++;
        while (cur < mn)
            ans.push_back({1, cur++});
    }

    cout << ans.size() << "\n";
    for (auto [key, val] : ans)
        cout << key << " " << val << "\n";
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
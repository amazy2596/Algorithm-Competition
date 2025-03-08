#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct point
{
    int x, y, type;
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<point> p;
    for (int i = 0; i < n; i++)
    {
        int x, y, type;
        cin >> x >> y >> type;
        p.emplace_back(x, y, type);
    }

    int x, y;
    cin >> x >> y;

    auto calc = [&](int x1, int y1) -> long double
    {
        return sqrtl((x - x1) * (x - x1) + (y - y1) * (y - y1));
    };

    vector<pair<long double, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
        v.push_back({calc(p[i].x, p[i].y), {i, p[i].type}});

    sort(v.begin(), v.end());

    vector<int> ans;
    map<int, int> mp;
    int mx = -1, type = -1;
    for (int i = 0; i <= n; i++)
    {
        mp[v[i].second.second]++;
        if (mp[v[i].second.second] > mx)
        {
            mx = mp[v[i].second.second];
            type = v[i].second.second;
        }
        else if (mp[v[i].second.second] == mx)
        {
            if (v[i].second.second < type)
                type = v[i].second.second;
        }
        ans.push_back(type);
    }
    
    while (q--)
    {
        int k;
        cin >> k;
        cout << ans[k - 1] << "\n";
    }
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
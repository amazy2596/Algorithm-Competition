#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    auto check = [&](pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
    {
        if(p1.second == p2.second || p1.second == p3.second)
            return p1.second == p2.second && p1.second == p3.second;

        double a = (p1.first - p2.first) * 1.0 / (p1.second-p2.second);
        double b = (p1.first - p3.first) * 1.0 / (p1.second-p3.second);

        return abs(a - b) < 1e-6;
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        map<int, vector<int>> dist;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            
            int dis = (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second);

            dist[dis].push_back(j);
        }

        for (auto &[dis, v] : dist)
        {
            for (int j = 0; j < v.size(); j++)
            {
                for (int k = j + 1; k < v.size(); k++)
                {
                    if (!check(a[i], a[v[j]], a[v[k]]))
                        ans++;
                }
            }
        }
    }

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
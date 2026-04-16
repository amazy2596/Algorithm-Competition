// Problem: L2-4 对称中心
// URL: https://ac.nowcoder.com/acm/contest/130247/L
// Author: amazy
// Date: 2026-03-14 16:08:12

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (auto &[x, y] : p) cin >> x >> y;

    map<pair<double, double>, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            auto [x1, y1] = p[i];
            auto [x2, y2] = p[j];
            double cx = (x1 + x2) * 1.0 / 2, cy = (y1 + y2) * 1.0 / 2;
            mp[{cx, cy}]++;
        }
    }

    cout << fixed << setprecision(1);
    for (auto [key, val] : mp)
    {
        if (val == n)
        {
            cout << "Yes\n";
            cout << key.first << " " << key.second << "\n";
            return;
        }
    }
    cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
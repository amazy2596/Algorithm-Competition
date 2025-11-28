// Problem: 小红下象棋
// URL: https://ac.nowcoder.com/acm/contest/123787/C
// Author: amazy
// Date: 2025-11-28 19:22:18

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int x, y, n;
    cin >> x >> y >> n;
    vector<pair<int, int>> p(n);
    map<pair<int, int>, int> mp;
    for (auto &[x, y] : p) 
    {
        cin >> x >> y;
        for (auto [dx, dy] : vector<pair<int, int>> {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}})
        {
            int nx = x + dx, ny = y + dy;
            mp[{nx, ny}] = 1;
        }
    }

    if (mp.find({x, y}) != mp.end())
    {
        bool f = 0;
        for (auto [dx, dy] : vector<pair<int, int>> {{1, 1}, {1, 1}, {1, -1}, {1, -1}, {-1, -1}, {-1, -1}, {-1, 1}, {-1, 1}})
        {
            int nx = x + dx, ny = y + dy;
            if (mp.find({nx, ny}) == mp.end()) f = 1;
        }

        if (f) cout << "C\n";
        else cout << "B\n";
    }
    else 
    {
        bool f = 0;
        for (auto [dx, dy] : vector<pair<int, int>> {{1, 1}, {1, 1}, {1, -1}, {1, -1}, {-1, -1}, {-1, -1}, {-1, 1}, {-1, 1}})
        {
            int nx = x + dx, ny = y + dy;
            if (mp.find({nx, ny}) == mp.end()) f = 1;
        }

        if (f) cout << "C\n";
        else cout << "A\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
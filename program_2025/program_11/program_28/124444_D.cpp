// Problem: 强风追踪
// URL: https://ac.nowcoder.com/acm/contest/124444/D
// Author: amazy
// Date: 2025-11-28 20:33:14

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n, o, p;
    cin >> n >> o >> p;
    string s;
    cin >> s;
    int x = 0, y = 0;
    set<pair<int, int>> vis;
    vis.insert({x, y});
    string ans;
    for (int i = 0; i < n; i++)
    {
        vis.insert({x, y});
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        if (s[i] == 'L') x--;
        if (s[i] == 'R') x++;
        if (vis.count({x - o, y - p})) ans += '1';
        else ans += '0';
    }

    cout << ans << "\n";
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
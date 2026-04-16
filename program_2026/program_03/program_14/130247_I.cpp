// Problem: L2-1 流水
// URL: https://ac.nowcoder.com/acm/contest/130247/I
// Author: amazy
// Date: 2026-03-14 14:21:40

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    set<pair<int, int>> s;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int i = -8; i <= 8; i++)
        {
            for (int j = -8; j <= 8; j++)
            {
                int nx = x + i, ny = y + j;
                if (nx < 1 || nx > n || ny < 1 || ny > m || abs(i) + abs(j) > 8) continue;
                s.insert({x + i, y + j});
            }
        }
    }
    cout << s.size() << "\n";
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
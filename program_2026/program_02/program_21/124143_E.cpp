// Problem: the world
// URL: https://ac.nowcoder.com/acm/contest/124143/E
// Author: amazy
// Date: 2026-02-21 14:49:22

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

const int N = 1005;
int vis[N][N][4];

struct node
{
    int x, y, time, cnt, parity, use;
};

void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                vis[i][j][k] = 1e9;
            }
        }
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    map<pair<int, int>, int> odd, even;
    for (int i = 0; i < k; i++) 
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        odd[{x1, y1}] = 1;
        even[{x2, y2}] = 1;
    }

    int ans = 1e9;
    queue<node> q;
    q.push({1, 1, 1, 0, 0, 0});
    while (!q.empty())
    {
        auto [x, y, time, cnt, parity, use] = q.front();
        q.pop();
        if (vis[x][y][(time & 1) + (use * 2)] != 1e9) continue;
        vis[x][y][(time & 1) + (use * 2)] = time;

        // cout << x << " " << y << " " << time << " " << cnt << " " << parity << " " << use << "\n";

        for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {1, 0}, {0, -1}, {-1, 0}})
        {
            int nx = x + dx, ny = y + dy;
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;

            if (use == 0)
            {
                if ((time & 1) == 1 && odd.find({nx, ny}) == odd.end()) q.push({nx, ny, time + 1, 1, (time & 1), 1});
                if ((time & 1) == 0 && even.find({nx, ny}) == even.end()) q.push({nx, ny, time + 1, 1, (time & 1), 1});
                if ((time & 1) == 1 && even.find({nx, ny}) == even.end()) q.push({nx, ny, time + 1, 0, 0, 0});
                if ((time & 1) == 0 && odd.find({nx, ny}) == odd.end()) q.push({nx, ny, time + 1, 0, 0, 0});

            }
            else
            {
                if (cnt == 1)
                {
                    if (parity == 1 && odd.find({nx, ny}) == odd.end()) q.push({nx, ny, time + 1, cnt - 1, parity, use});
                    if (parity == 0 && even.find({nx, ny}) == even.end()) q.push({nx, ny, time + 1, cnt - 1, parity, use});
                }
                else 
                {
                    if ((time & 1) == 1 && even.find({nx, ny}) == even.end()) q.push({nx, ny, time + 1, 0, parity, use});
                    if ((time & 1) == 0 && odd.find({nx, ny}) == odd.end()) q.push({nx, ny, time + 1, 0, parity, use});
                }
            }
        }
    }

    for (int k = 0; k < 4; k++) ans = min(ans, vis[n][m][k]);
    cout << (ans == 1e9 ? -1 : ans - 1) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    init();
    while (T--)
        solve();
    return 0;
}
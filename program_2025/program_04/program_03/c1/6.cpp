#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    if (g[0][0] != 0)
    {
        cout << "-1\n";
        return;
    }

    map<int, pair<int, int>> mp = {{0, {-1, 0}}, {1, {-1, 1}}, {2, {0, 1}}, {3, {1, 1}}, {4, {1, 0}}, {5, {1, -1}}, {6, {0, -1}}, {7, {-1, -1}}};
    map<pair<int, int>, map<int, int>> direct;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 8; k++)
                direct[{i, j}][k]++;

    set<vector<int>> s;
    map<pair<int, int>, int> vis;
    vis[{0, 0}]++;

    auto dfs = [&](auto dfs, int i, int j, int curTar, vector<int> cur) -> void
    {
        if (cur.size() == n * n - 1 && i == n - 1 && j == n - 1)
        {
            s.insert(cur);
            return;
        }

        for (auto [dir, _] : direct[{i, j}])
        {
            auto [dx, dy] = mp[dir];
            int nx = i + dx, ny = j + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            
            if (g[nx][ny] == curTar && !vis[{nx, ny}])
            {
                cur.push_back(dir);
                vis[{nx, ny}]++;

                if (dir == 1)
                {
                    direct[{i - 1, j}].erase(3);
                    direct[{i, j + 1}].erase(7);
                }
                else if (dir == 3)
                {
                    direct[{i, j + 1}].erase(5);
                    direct[{i + 1, j}].erase(1);
                }
                else if (dir == 5)
                {
                    direct[{i, j - 1}].erase(3);
                    direct[{i + 1, j}].erase(7);
                }
                else if (dir == 7)
                {
                    direct[{i - 1, j}].erase(5);
                    direct[{i, j - 1}].erase(1);
                }

                dfs(dfs, nx, ny, (curTar + 1) % k, cur);

                cur.pop_back();
                vis.erase({nx, ny});

                if (dir == 1)
                {
                    direct[{i - 1, j}][3]++;
                    direct[{i, j + 1}][7]++;
                }
                else if (dir == 3)
                {
                    direct[{i, j + 1}][5]++;
                    direct[{i + 1, j}][1]++;
                }
                else if (dir == 5)
                {
                    direct[{i, j - 1}][3]++;
                    direct[{i + 1, j}][7]++;
                }
                else if (dir == 7)
                {
                    direct[{i - 1, j}][5]++;
                    direct[{i, j - 1}][1]++;
                }
            }

        }
    };

    dfs(dfs, 0, 0, 1, {});

    if (s.size())
    {
        auto &ans = *s.begin();
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i];
    }
    else 
        cout << "-1\n";
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
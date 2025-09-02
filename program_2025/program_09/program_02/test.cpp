#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

class Solution {
public:
    struct node
    {
        int x, y, t, mask;
    };

    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int k = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    k = max(k, grid[i][j] - 'a' + 1);
            }
        }

        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(1 << k)));
        auto bfs = [&](int i, int j)
        {
            queue<node> q;
            q.push({i, j, 0, 0});

            while (!q.empty())
            {
                auto [x, y, t, mask] = q.front();
                q.pop();

                if (vis[x][y][mask])
                    continue;
                vis[x][y][mask] = 1;

                if (mask == (1 << k) - 1)
                    return t;

                for (auto [dx, dy] : dirs)
                {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#')
                        continue;

                    int nt = t + 1;
                    int nmask = mask;
                    if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f')
                        nmask |= (1 << (grid[nx][ny] - 'a'));
                    if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F' && (nmask & (1 << (grid[nx][ny] - 'A'))) == 0)
                        continue;

                    q.push({nx, ny, nt, nmask});
                }
            }

            return -1;
        };

        int ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '@')
                {
                    ans = bfs(i, j);
                }
            }
        }

        return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];
    Solution s;
    cout << s.shortestPathAllKeys(g);
}

int main()
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
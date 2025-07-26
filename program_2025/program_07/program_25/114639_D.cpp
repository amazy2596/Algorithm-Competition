#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct node
{
    int x, y, cost;

    bool operator<(node o) const
    {
        return cost > o.cost;
    }
};

map<char, int> mp = {{'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};
vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i], s[i] = " " + s[i];

    priority_queue<node> q;
    q.push({1, 1, 0});
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, inf));
    dist[1][1] = 0; 
    while (!q.empty())
    {
        auto [x, y, cost] = q.top();
        q.pop();

        if (x == n && y == m && dist[x][y] <= k)
        {
            cout << "YES\n";
            return;
        }

        if (dist[x][y] < cost)
            continue;

        for (int i = 0; i < 4; i++)
        {
            auto [dx, dy] = dir[i];
            int nx = x + dx, ny = y + dy;
            int nc = cost + (mp[s[x][y]] != i);
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;

            if (nc < dist[nx][ny] && nc <= k)
            {
                dist[nx][ny] = nc;
                q.push({nx, ny, nc});
            }
        }
    }

    if (dist[n][m] <= k)
        cout << "YES\n";
    else 
        cout << "NO\n";
}

signed main()
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
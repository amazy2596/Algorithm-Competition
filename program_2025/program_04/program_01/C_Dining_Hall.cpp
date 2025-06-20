#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct node
{
    int dist, x, y, tx, ty;

    bool operator<(const node other) const
    {
        if (dist == other.dist && tx == other.tx)
            return ty > other.ty;
        else if (dist == other.dist)
            return tx > other.tx;
        return dist > other.dist;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    priority_queue<node> q1;
    queue<array<int, 3>> q;
    q.push({0, 0, 0});
    int mx = -1;

    map<pair<int, int>, int> vis_path;
    map<pair<int, int>, int> vis_desk;
    while (!q.empty())
    {
        auto [x, y, dist] = q.front();
        q.pop();

        if (vis_path[{x, y}])
            continue;
        vis_path[{x, y}]++;

        if (vis_desk[{x, y}])
            continue;
        vis_desk[{x, y}]++;

        if (x % 3 == 1 && y % 3 == 1)
            q1.push({dist, (x - 1) / 3, (y - 1) / 3, x, y});
        else if (x % 3 == 1 && y % 3 == 2)
            q1.push({dist, (x - 1) / 3, (y - 2) / 3, x, y});
        else if (x % 3 == 2 && y % 3 == 1)
            q1.push({dist, (x - 2) / 3, (y - 1) / 3, x, y});
        else if (x % 3 == 2 && y % 3 == 2)
            q1.push({dist, (x - 2) / 3, (y - 2) / 3, x, y});
        else
        {
            for (auto [dx, dy] : vector<pair<int, int>> {{0, 1}, {1, 0}, {0, -1}, {-1, 0}})
            {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0)
                    continue;
                q.push({nx, ny, dist + 1});
            }
        }

        if (q1.size() >= 4 * n && mx == -1)
            mx = dist;

        if (mx != -1 && !q.empty() && q.front()[2] > mx)
            break;
    }

    priority_queue<node> q2 = q1;
    map<pair<int, int>, int> mp1, mp2;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            while (!q1.empty())
            {
                auto [_, x, y, tx, ty] = q1.top();
                q1.pop();
                if (!mp2.contains({tx, ty}))
                {
                    mp1[{x, y}]++;
                    mp2[{tx, ty}]++;
                    cout << tx << " " << ty << "\n";
                    break;
                }
            }
        }
        else 
        {
            while (!q2.empty())
            {
                auto [_, x, y, tx, ty] = q2.top();
                q2.pop();
                if (!mp1.contains({x, y}) && !mp2.contains({tx, ty}))
                {
                    mp1[{x, y}]++;
                    mp2[{tx, ty}]++;
                    cout << tx << " " << ty << "\n";
                    break;
                }
            }
        }
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
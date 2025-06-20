#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
    int i, j, f;
};

void solve()
{
    int n;
    cin >> n;
    bool ans = false;
    vector<string> s(3);
    vector<vector<bool>> vis(3, vector<bool>(n + 1, false));
    for (int i = 1; i <= 2; i++)
    {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    auto bfs = [&](node beg)
    {
        queue<node> q;
        q.push(beg);
        while (!q.empty())
        {
            auto [i, j, f] = q.front();
            q.pop();
            if (i == 2 && j == n)
            {
                ans = true;
                break;
            }
            if (vis[i][j])
                continue;
            vis[i][j] = true;
            if (f)
            {
                for (auto [dx, dy] : vector<pair<int, int>> {{-1, 0}, {0, 1}, {1, 0}, {0, -1}})
                {
                    int new_i = i + dx, new_j = j + dy;
                    if (new_i < 1 || new_i > 2 || new_j < 1 || new_j > n)
                        continue;
                    q.push({new_i, new_j, f ^ 1});
                }
            }
            else
            {
                if (s[i][j] == '<')
                    q.push({i, j - 1, f ^ 1});
                else
                    q.push({i, j + 1, f ^ 1});
            }
        }
    };
    bfs({1, 1, true});
    cout << (ans ? "YES\n" : "NO\n");
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
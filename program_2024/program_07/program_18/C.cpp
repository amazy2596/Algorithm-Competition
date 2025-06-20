// #include <bits/stdc++.h>
// using intt = long long;
// using namespace std;

// const int N = 2e6;
// int n, ans = 0;
// vector<string> s(2);
// struct node
// {
//     int x, y, steps, dir;
// };

// bool vis[3][N + 5][4];

// void init()
// {
//     for (int i = 0; i < 2; i++)
//         for (int j = 0; j < N; j++)
//             for (int k = 0; k < 4; k++)
//                 vis[i][j][k] = 0;
// }

// void bfs(int x, int y)
// {
//     init();
//     queue<node> q;
//     for (int i = 0; i < 4; i++)
//         q.push({x, y, 0, i});
//     while (!q.empty())
//     {
//         node top = q.front();
//         q.pop();
//         if (vis[top.x][top.y][top.dir])
//             continue;
//         vis[top.x][top.y][top.dir] = 1;
//         ans = max(ans, top.steps);
//         for (auto [dx, dy] : vector<pair<int, int>> {{-1, 0}, {1, 0}, {0, 1}, {0, -1}})
//         {
//             int new_x = top.x + dx;
//             int new_y = top.y + dy;
//             if (new_x < 0 || new_x >= 2 || new_y < 0 || new_y >= n || s[new_x][new_y] == 'W' || dy == -1)
//                 continue;
//             if (top.dir == 0 && dx == 1)
//                 continue;
//             if (top.dir == 2 && dx == -1)
//                 continue;
//             int new_dir;
//             if (dx == -1 && dy == 0)
//                 new_dir = 0;
//             else if (dx == 0 && dy == 1)
//                 new_dir = 1;
//             else if (dx == 1 && dy == 0)
//                 new_dir = 2;
//             else 
//                 new_dir = 3;
//             q.push({new_x, new_y, top.steps + 1, new_dir});
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(nullptr);
//     cin.tie(nullptr);
//     cin >> n;
//     for (int i = 0; i < 2; i++)
//         cin >> s[i];
//     vector<int> idx;
//     for (int i = 0; i < n; i++)
//         if (s[0][i] == 'W' && s[1][i] == 'W')
//             idx.push_back(i);
//     if (idx.size())
//     {
//         if (idx[0] != 0)
//         {
//             if (s[0][0] == 'R')
//                 bfs(0, 0);
//             if (s[1][0] == 'R')
//                 bfs(1, 0);
//         }
//         if (idx[idx.size() - 1] != n - 1)
//         {
//             if (s[0][n - 1] == 'R')
//                 bfs(0, n - 1);
//             if (s[1][n - 1] == 'R')
//                 bfs(1, n - 1);
//         }
//         for (int i = 1; i < idx.size() - 1; i++)
//         {
//             if (s[0][idx[i] + 1] == 'R')
//                 bfs(0, idx[i] + 1);
//             if (s[1][idx[i] + 1] == 'R')
//                 bfs(1, idx[i] + 1);
//         }
//     }
//     else 
//     {
//         if (s[0][0] == 'R')
//             bfs(0, 0);
//         if (s[1][0] == 'R')
//             bfs(1, 0);
//     }
//     cout << ans << "\n";
//     return 0;
// }

#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(2);
    for (int i = 0; i < 2; i++)
        cin >> s[i];
    int ans = 0, cur = 0;
    pair<int, int> last = {-1, 0};
    for (int i = 0; i < n; i++)
    {
        if (s[0][i] == 'W' && s[1][i] == 'W')
        {
            last.first = -1, last.second = i;
            ans = max(ans, cur);
            cur = 0;
        }
        else 
        {
            int distance = i - last.second - 1;
            if (s[0][i] == 'W')
            {
                cur++;
                if (last.first == 0 && distance % 2 == 1)
                    cur--;
                else if (last.first == 1 && distance % 2 == 0)
                    cur--;
                last.first = 0, last.second = i;
                if (i == n - 1 || s[1][i + 1] == 'W')
                {
                    ans = max(ans, cur), cur = 0;
                    last.first = 1, last.second = i + 1;
                }
            }
            else if (s[1][i] == 'W')
            {
                cur++;
                if (last.first == 0 && distance % 2 == 0)
                    cur--;
                else if (last.first == 1 && distance % 2 == 1)
                    cur--;
                last.first = 1, last.second = i;
                if (i == n - 1 || s[0][i + 1] == 'W')
                {
                    ans = max(ans, cur), cur = 0;
                    last.first = 0, last.second = i + 1;
                }
            }
            else 
                cur += 2;
        }
    }
    ans = max(ans, cur);
    cout << (ans ? ans - 1 : ans) << "\n";
    return 0;
}
#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int n, ans = 0, temp = 0, a[100], g[100][100];
bool vis[100][100];
vector<int> temp_order, ans_order;

void dfs(int x)
{
    if (temp > ans)
        ans = temp, ans_order = temp_order;
    for (int j = x + 1; j <= n; j++)
    {
        if (vis[x][j] || g[x][j] == 0)
            continue;
        vis[x][j] = 1;
        temp_order.push_back(j);
        temp += a[j];
        if (temp > ans)
            ans = temp, ans_order = temp_order;
        dfs(j);
        vis[x][j] = 0;
        temp -= a[j];
        temp_order.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n;
    // vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // vector<vector<int>> g(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> g[i][j];
    for (int i = 1; i <= n; i++)
    {
        temp += a[i];
        temp_order.push_back(i);
        dfs(i);
        temp -= a[i];
        temp_order.pop_back();
    }
    for (int i = 0; i < ans_order.size(); i++)
        cout << ans_order[i] << " ";
    cout << "\n" << ans;
    return 0;
}
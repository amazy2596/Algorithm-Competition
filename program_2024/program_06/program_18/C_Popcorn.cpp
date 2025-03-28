#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int n, m, ans = 1e9;
vector<int> idx, check;
vector<bool> vis(15);
vector<string> s(15);

void dfs()
{
    check.assign(15, 0);
    for (int i = 0; i < idx.size(); i++)
    {
        for (int j = 0; j < m; j++)
            check[j] += s[idx[i]][j] == 'o';
    }
    bool f = 1;
    for (int i = 0; i < m; i++)
        if (!check[i])
            f = 0;
    if (f && ans > idx.size())
        ans = idx.size();
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        idx.push_back(i);
        dfs();
        idx.pop_back();
        vis[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    dfs();
    cout << ans << "\n";
    return 0;
}
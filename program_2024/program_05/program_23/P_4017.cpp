#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 5005, mod = 80112002;
int n, m, ans = 0;
vector<int> mx(N, 0);
vector<vector<int>> a(N);

int dfs(int i)
{
    if (mx[i])
        return mx[i];
    mx[i] = 1;
    int temp = mx[i];
    for (int j = 0; j < a[i].size(); j++)
    {
        mx[i] = max(mx[i], (temp + dfs(a[i][j])) % mod);
    }
    return mx[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dfs(i)) % mod;
    cout << ans % mod;
    return 0;
}
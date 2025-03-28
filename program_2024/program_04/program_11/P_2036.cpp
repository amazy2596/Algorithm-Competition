#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int n;
int ans = INT32_MAX;
vector<bool> vis(15, 0);
int s = 1, b = 0;
pair<int, int> a[15];

void dfs()
{
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        s *= a[i].first, b += a[i].second;
        ans = min(ans, abs(s - b));
        dfs();
        vis[i] = 0;
        s /= a[i].first, b -= a[i].second;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    dfs();
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int n;
pair<int, int> a[20];
vector<bool> vis(20, 0);
double ans = INT32_MAX;
vector<pair<int, int>> order = {{0, 0}};

void dfs()
{
    if (order.size() == n + 1)
    {
        double temp = 0;
        for (int i = 1; i < order.size(); i++)
            temp += sqrt((order[i].first - order[i - 1].first) * (order[i].first - order[i - 1].first) + (order[i].second - order[i - 1].second) * (order[i].second - order[i - 1].second));
        ans = min(ans, temp);
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        order.push_back({a[i].first, a[i].second});
        dfs();
        vis[i] = 0;
        order.pop_back();
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
    cout << fixed << setprecision(2) << ans;
    return 0;
}
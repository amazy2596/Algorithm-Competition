#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g(m);
    for (int i = 0; i < m; i++)
        cin >> g[i].first >> g[i].second;
    intt ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, 1ll * (n - i) * i);
    cout << ans << "\n";
    return 0;
}
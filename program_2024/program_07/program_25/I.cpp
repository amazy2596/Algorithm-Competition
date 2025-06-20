#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    intt n, m;
    cin >> n >> m;
    unordered_map<int, set<int>> mp;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        mp[v].insert(u);
    }
    int l = 1, r = 2;
    intt ans = (n * (n + 1)) / 2;
    while (r <= n && l <= r)
    {
        if (l == r)
        {
            r++;
            continue;
        }
        for (int i = r - 1; i >= l; i--)
        {
            if (mp[r].count(i) == 0)
            {
                ans -= (i - l + 1) * (n - r + 1);
                l = i + 1;
                break;
            }
        }
        r++;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    solve();
    return 0;
}
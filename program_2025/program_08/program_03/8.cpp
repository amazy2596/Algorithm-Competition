#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1), vis(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    int j = 1;
    for (int i = 1; i <= m; i++)
    {
        while (j <= n && b[i] != a[j])
            j++;
        if (b[i] == a[j])
            vis[j] = 1;
    }

    j = 1;
    for (int i = 1; i <= m; i++)
    {
        while (j <= n)
        {
            if (vis[j])
                j++;
            else if (a[j] == b[i])
                break;
            else 
                j++;
        }
        if (b[i] == a[j])
            vis[j] = 1;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += vis[i];

    if (cnt == 2 * m)
        cout << "Yes\n";
    else 
        cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
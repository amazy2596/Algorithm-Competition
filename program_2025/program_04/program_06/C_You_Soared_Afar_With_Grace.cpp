#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], p[a[i]] = i;
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<pair<int, int>> ans;
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[i])
        {
            if (n % 2 == 0 || x)
            {
                cout << "-1\n";
                return;
            }
            x = i;
        }
        else if (b[p[b[i]]] != a[i])
        {
            cout << "-1\n";
            return;
        }
    }

    auto work = [&](int x, int y)
    {
        if (x == y)
            return;

        ans.push_back({x, y});
        swap(a[x], a[y]);
        swap(p[a[x]], p[a[y]]);
        swap(b[x], b[y]);
    };

    if (n & 1)
        work(x, (n + 1) / 2);

    for (int i = 1; i <= n / 2; i++)
    {
        work(p[b[i]], n - i + 1);  
    }

    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        if (a[i] != b[n - i + 1])
        {
            cout << "-1\n";
            return;
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
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
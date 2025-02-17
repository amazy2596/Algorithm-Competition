#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    bool f = 0;
    for (int i = 0; i < m; i++)
    {
        auto &[x, y] = a[i];
        int c;
        cin >> x >> y >> c;
        if ((y - x + 1) % 2 == 0)
            f = 1;
    }

    if (f)
    {
        for (int i = n; i >= 1; i--)
            cout << i << " \n"[i == 1];
        return;
    }

    int j = 0;
    if (n % 2 == 0)
    {
        for (int i = n - 1; i >= 1;)
        {
            cout << i << " ";
            if (j % 2 == 0)
                i++;
            else 
                i -= 3;
            j++;
        }
    }
    else 
    {
        cout << n << " ";
        for (int i = n - 2; i >= 1;)
        {
            cout << i << " ";
            if (j % 2 == 0)
                i++;
            else 
                i -= 3;
            j++;
        }
    }

    cout << "\n";
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
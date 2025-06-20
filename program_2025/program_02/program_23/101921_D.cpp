#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {    
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
    }
    
    vector<int> last = {0, a[1][1]};
    for (int i = 1; i < n; i++)
    {
        vector<int> cur = {0};
        int beg = 0;
        for (int j = 1; j <= i; j++)
        {
            auto it = lower_bound(a[i + 1].begin() + beg + 1, a[i + 1].end(), last[j]);
            if (it == a[i + 1].end())
            {
                cout << i << "\n";
                return;
            }
            cur.push_back(*it);
            beg = it - a[i + 1].begin();
        }

        if (beg < n)
            cur.push_back(a[i + 1][beg + 1]);
        else 
        {
            cout << i << "\n";
            return;
        }

        last = cur;
    }

    cout << n << "\n";
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
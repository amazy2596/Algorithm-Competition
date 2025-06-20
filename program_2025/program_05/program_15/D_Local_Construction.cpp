#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int mx = *max_element(a.begin(), a.end()) + 1;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == -1)
            a[i] = mx;
    }

    int l = 1, r = n;
    for (int i = 1; i <= mx; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[j] > i)
                    break;
                if (a[j] != i || p[j] != 0)
                    continue;
                p[j] = r--;
            }
            for (int j = n; j >= 1; j--)
            {
                if (a[j] != i || p[j] != 0)
                    continue;
                p[j] = r--;
            }
        }
        else 
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[j] > i)
                    break;
                if (a[j] != i || p[j] != 0)
                    continue;
                p[j] = l++;
            }
            for (int j = n; j >= 1; j--)
            {
                if (a[j] != i || p[j] != 0)
                    continue;
                p[j] = l++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << " ";
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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = (a[i] <= k ? 1 : -1);
        s[i] = s[i - 1] + a[i];
    }

    vector<int> preMax(n + 1, -1e9), preMin(n + 1, 1e9), sufMax(n + 2, -1e9);
    for (int i = 1; i <= n; i++)
    {
        preMax[i] = max(preMax[i - 1], s[i]);
        preMin[i] = min(preMin[i - 1], s[i]);
    }
    for (int i = n; i >= 1; i--)
        sufMax[i] = max(sufMax[i + 1], s[i]);
    
    int sn = s[n];

    for (int i = 1; i <= n - 2; i++)
    {
        if (s[i] >= 0 && sufMax[i + 1] >= s[i])
        {
            cout << "YES\n";
            return;
        }
    }

    for (int j = 2; j <= n - 1; j++)
    {
        if (s[j] <= sn)
        {
            if (preMax[j - 1] >= 0)
            {
                cout << "YES\n";
                return;
            }

            if (preMin[j - 1] <= s[j])
            {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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
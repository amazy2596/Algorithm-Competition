#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mp[a[i]]++;
    
    int len = 0, l = 0, r = -1;
    for (int i = 1; i <= n; i++)
    {
        if (mp[a[i]] == 1)
            len++;
        else 
        {
            if (len > r - l + 1)
            {
                r = i - 1;
                l = r - len + 1;
            }
            len = 0;
        }
    }

    if (len > r - l + 1)
    {
        r = n;
        l = n - len + 1;
    }
    if (l == 0)
        cout << "0\n";
    else 
        cout << l << " " << r << "\n";
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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    int ans = 0;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        map<int, int> mp;
        set<int> s;
        mp[0] = 1;
        f[i - 1] = 0;
        for (int j = i; j <= n; j++)
        {
            s.insert(a[j]);
            if (s.size() > 2)
            {
                i = j;
                s.clear();
                while (i >= 1)
                {
                    s.insert(a[i]);
                    if (s.size() > 2)
                        break;
                    i--;
                }
                break;
            }
            f[j] = f[j - 1];
            if (a[j] == a[i])
                f[j]++;
            else 
                f[j]--;
            ans += mp[f[j]];
            mp[f[j]]++;
            if (j == n)
                i = n;
        }
    }

    cout << ans << "\n";
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
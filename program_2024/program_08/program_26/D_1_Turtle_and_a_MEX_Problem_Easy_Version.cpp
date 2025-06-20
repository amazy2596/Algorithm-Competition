#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
        sort(a[i].begin(), a[i].end());
        a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
        int mex = 0;
        int k = 0;
        while (k < l)
        {
            if (mex == a[i][k])
                mex++;
            else 
                break;
            k++;
        }
        int to_mex = mex + 1;
        while (k < l)
        {
            if (to_mex == a[i][k])
                to_mex++;
            else 
                break;
            k++;
        }
        mp[mex].push_back(to_mex);
    }
    int mx = 0;
    for (auto [mex, v] : mp)
        for (auto vv : v)
            mx = max(mx, vv);
    int N = 2e5 + 1;
    int ans = 0;
    if (m >= N)
        ans += (m + N) * (m - N + 1) / 2;
    
    for (int i = 0; i <= min(m, N - 1); i++)
        ans += max(mx, i);

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
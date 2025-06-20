#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
        cin >> a[i].second;
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].second == 1)
        {
            int mc = 0;
            if (i < n / 2)
                mc = a[n / 2].first;
            else 
                mc = a[n / 2 - 1].first;
            ans = max(ans, a[i].first + k + mc);
        }
    }


    int l = 0, r = 1e10;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        vector<int> temp;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i].first >= mid)
                cnt++;
            else if (a[i].second == 1)
                temp.push_back(mid - a[i].first);
        }

        int kk = k;

        for (int i = temp.size() - 1; i >= 0; i--)
        {
            if (kk >= temp[i])
            {
                kk -= temp[i];
                cnt++;
            }
        }

        if (cnt >= (n + 1) / 2)
            l = mid;
        else 
            r = mid - 1;
    }
    
    cout << max(ans, a[n - 1].first + l) << "\n";
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
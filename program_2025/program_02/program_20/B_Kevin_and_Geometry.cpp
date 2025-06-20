#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    int cnt = 0, tar = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    for (auto [key, val] : mp)
    {
        if (val >= 2)
        {
            cnt++;
            tar = key;
        }
    }

    if (cnt == 0)
        cout << -1 << "\n";
    else if (cnt == 1)
    {
        sort(a.begin(), a.end());
        int m = 2;
        while (m--)
        {
            auto it = lower_bound(a.begin(), a.end(), tar);
            a.erase(it);
        }

        for (int i = 1; i < a.size(); i++)
        {
            if (abs(a[i] - a[i - 1]) < 2 * tar)
            {
                cout << tar << " " << tar << " " << a[i - 1] << " " << a[i] << "\n";
                return;
            }
        }

        cout << "-1\n";
    }
    else 
    {
        int x = 0, y = 0;
        for (auto [key, val] : mp)
        {
            if (val >= 2)
            {
                if (x == 0)
                    x = key;
                else if (y == 0)
                    y = key;
                else 
                    break;
            }
        }

        cout << x << " " << x << " " << y << " " << y << "\n";
    }
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
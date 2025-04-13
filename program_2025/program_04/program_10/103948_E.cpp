#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    sort(a.begin(), a.end());
    map<int, int> mp;
    int edA = -1, edB = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][0] > edA)
            edA = a[i][1], mp[a[i][2]]++;
        else if (a[i][0] > edB)
            edB = a[i][1];
        else
        {
            cout << "-1\n";
            return;
        }
    }

    cout << mp.size() << "\n";
    for (auto [key, val] : mp)
        cout << key << " ";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
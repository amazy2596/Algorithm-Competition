#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> a[i], mp[a[i]]++;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (mp.find((a[i] | a[j])) == mp.end())
            {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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
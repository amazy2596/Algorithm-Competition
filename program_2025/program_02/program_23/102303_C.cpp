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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mp.count(a[i]))
        {
            cout << "NO\n";
            return;
        }
        mp[a[i]]++;
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j)
    {
        return a[i] < a[j];
    });
    
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << p[i] + 1 << " ";
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
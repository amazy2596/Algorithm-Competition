#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n; 
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] > a[i])
        {
            int diff = b[i] - a[i];
            a[i] = b[i] + diff;
            cnt += diff;
        }
    }
    for (int i = 0; i < n; i++)
    {
        a[i] -= cnt;
        if (a[i] < b[i])
        {
            cout << "NO\n";
            return;
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
    cin >> T;
    while (T--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int t, n, m;
    cin >> t >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++)
        t -= a[i];

    if (t >= 0)
        cout << t / 40 << "\n";
    else 
        cout << "-1\n";
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
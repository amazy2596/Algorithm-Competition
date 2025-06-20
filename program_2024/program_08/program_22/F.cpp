#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];
    vector<int> idx(n);
    int mx = l[n - 1], index = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        idx[i] = index;
        if (l[i] >= mx)
            mx = l[i], index = i;
    }
    idx[n - 1] = -1;
    int i = 0, ans = 0;
    while (idx[i] != -1)
    {
        i = idx[i];
        ans++;
    }
    cout << ans - 1 << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
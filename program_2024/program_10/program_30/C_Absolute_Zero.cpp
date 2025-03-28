#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n; 
    vector<int> a(n);
    bool f1 = 0, f2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 1)
            f1 = 1;
        if (a[i] % 2 == 0)
            f2 = 1;
    }
    if (f1 && f2)
    {
        cout << -1 << "\n";
        return;
    }
    vector<int> ans;
    for (int k = 29; k >= 0; k--)
    {
        ans.push_back(1 << k);
        for (int i = 0; i < n; i++)
            a[i] = abs(a[i] - (1 << k));
    }
    if (f2)
        ans.push_back(1);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
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
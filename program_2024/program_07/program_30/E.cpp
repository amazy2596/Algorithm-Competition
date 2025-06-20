#include <bits/stdc++.h>
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
    int ans = 0;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (a[i] > b[i]);
        if (a[i] == b[i])
            temp++;
    }
    if (temp % 2 == 1)
        ans += temp / 2 + 1;
    else 
        ans += temp / 2;
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mx = max(a[0] + c, *max_element(a.begin(), a.end()));
    int idx = (mx == a[0] + c ? 0 : find(a.begin(), a.end(), mx) - a.begin());
    int sum = c;
    for (int i = 0; i < n; i++)
    {
        if (i == idx)
            cout << 0 << " ";
        else if (a[i] + sum >= mx)
            cout << i << " ";
        else
            cout << i + 1 << " ";
        sum += a[i];
    }
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
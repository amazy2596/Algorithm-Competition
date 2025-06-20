#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum >= a[i] - 1)
            sum += a[i];
    }
    if (sum >= n)
        cout << "Cool!\n";
    else 
        cout << sum + 1 << "\n";
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
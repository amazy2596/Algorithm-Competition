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
    bool f = 1;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i + 1] - a[i]) % 2 == 1)
        {
            f = 0;
            break;
        }
    }
    if (f)
    {
        if (n == 1)
        {
            cout << 1 << "\n";
            cout << a[0] << "\n";
            return;
        }
        int ans = 0;
        vector<int> x;
        while (ans <= 40 && a[0] != 0)
        {
            int cur = (a[0] + a[1]) / 2;
            for (int i = 0; i < a.size(); i++)
                a[i] = abs(a[i] - cur);
            x.push_back(cur);
            ans++;
            sort(a.begin(), a.end());
            a.erase(unique(a.begin(), a.end()), a.end());
        }
        if (ans > 40)
            cout << "-1\n";
        else 
        {
            cout << ans << "\n";
            for (int i = 0; i < x.size(); i++)
                cout << x[i] << " ";
            cout << "\n";
        }
    }
    else 
        cout << "-1\n";
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
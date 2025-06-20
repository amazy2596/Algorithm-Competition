#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    const int mod = 998244353;
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        int cnt = ceil(sum * 1.0 / (i + 1));
        while (true)
        {
            bool f = 1;
            for (int j = 0; j < i + 1 && j < n - 1; j++)
            {
                while (a[j] < cnt)
                {
                    if (a[j] < a[j + 1])
                    {
                        a[j]++, a[j + 1]--;
                        f = 0;
                    }
                    else
                        break;
                }
            }
            for (int j = 0; j < i + 1 && j < n; j++)
                cout << a[j] << " ";
            cout << "\n";
            if (f)
                break;
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
        ans = (ans * a[i]) % mod;
    cout << ans % mod << "\n";
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
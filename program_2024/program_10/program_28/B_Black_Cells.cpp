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
    if (n == 1)
        cout << 1 << "\n";
    else if (n % 2 == 0)
    {
        int ans = 0;
        for (int i = 1; i < n; i += 2)
            ans = max(ans, abs(a[i - 1] - a[i]));
        cout << ans << "\n";
    }
    else
    {
        auto get = [&]()
        {
            int temp = 0;
            for (int j = 1; j < a.size(); j += 2)
                temp = max(temp, a[j] - a[j - 1]);
            return temp;
        };
        int ans = 1e18 + 5;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (a[i] != 0)
                {
                    a.insert(a.begin(), a[i] - 1);
                    ans = min(ans, get());
                    a.erase(a.begin());
                }
                if (a[i] + 1 != a[i + 1])
                {
                    a.insert(a.begin() + i + 1, a[i] + 1);
                    ans = min(ans, get());
                    a.erase(a.begin() + i + 1);
                }
            }
            else if (i == n - 1)
            {
                if (a[i] != 1e18)
                {
                    a.insert(a.begin() + i + 1, a[i] + 1);
                    ans = min(ans, get());
                    a.erase(a.begin() + i + 1);
                }
                if (a[i - 1] != a[i] - 1)
                {
                    a.insert(a.begin() + i, a[i] - 1);
                    ans = min(ans, get());
                    a.erase(a.begin() + i);
                }
            }
            else
            {
                if (a[i - 1] + 1 != a[i])
                {
                    a.insert(a.begin() + i, a[i] - 1);
                    ans = min(ans, get());
                    a.erase(a.begin() + i);
                }
                if (a[i] + 1 != a[i])
                {
                    a.insert(a.begin() + i + 1, a[i] + 1);
                    ans = min(ans, get());
                    a.erase(a.begin() + i + 1);
                }
            }
        }
        cout << ans << "\n";
    }
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
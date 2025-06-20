#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    string s;
    cin >> s;
    s = ' ' + s;
    int ans = 0, r = n;
    for (int l = 1; l <= n; l++)
    {
        if (s[l] == 'L')
        {
            while (true)
            {
                if (s[r] == 'R' || r <= l)
                    break;
                r--;
            }

            if (r <= l)
                break;

            ans += pre[r] - pre[l - 1];

            r--;
        }
    }

    cout << ans << "\n";
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
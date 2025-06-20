#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    long double a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        long double t;
        cin >> t;
        a += t;
    }
    for (int i = 0; i < m; i++)
    {
        long double t;
        cin >> t;
        b += t;
    }
    for (int i = 0; i < p; i++)
    {
        long double t;
        cin >> t;
        c += t;
    }

    long double sum = a + b + c;
    long double avg = sum / 3;
    vector<long double> ans(6);
    if (a < avg)
    {
        if (b > avg)
            ans[0] = min(avg - a, b - avg), a -= min(avg - a, b - avg);
        if (c > avg)
            ans[1] = min(avg - a, c - avg), a -= min(avg - a, c - avg);
    }
    if (b < avg)
    {
        if (a > avg)
            ans[2] = min(avg - b, a - avg), b -= min(avg - b, a - avg);
        if (c > avg)
            ans[3] = min(avg - b, c - avg), b -= min(avg - b, c - avg);
    }
    if (c < avg)
    {
        if (a > avg)
            ans[4] = min(avg - c, a - avg), c -= min(avg - c, a - avg);
        if (b > avg)
            ans[5] = min(avg - c, b - avg), c -= min(avg - c, b - avg);
    }

    for (int i = 0; i < 6; i++)
        cout << fixed << setprecision(2) << ans[i] << " ";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
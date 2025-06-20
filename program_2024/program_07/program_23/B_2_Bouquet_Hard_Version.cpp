#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    const int N = 2e5 + 5;
    intt n, m;
    cin >> n >> m;
    vector<pair<intt, intt>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
        cin >> a[i].second;
    intt ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        intt x = a[i].first;
        intt max_x = min(a[i].second, m / x);
        // for (int k = 0; k <= max_x; k++)
        // {
            ans = max(ans, 1ll * max_x * x);
            if (i < n - 1 && x + 1 == a[i + 1].first)
            {
                intt y = a[i + 1].first;
                intt max_y = min(a[i + 1].second, (m - max_x * x) / y);
                ans = max(ans, max_x * x + max_y * y);
                max_y = min(a[i + 1].second, m / y);
                max_x = min(a[i + 1].second, (m - max_y * y) / x);
                ans = max(ans, max_x * x + max_y * y);
            }
        // }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
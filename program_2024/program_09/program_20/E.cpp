#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), cnt(N), x(N), y(N);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]] = 1;
    }
    for (int i = 1; i <= 1e6; i++)
    {
        for (int j = i; j <= 1e6; j += i)
        {
            x[j] += cnt[i];
            y[j]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 1e6; i++)
        if (x[i] == y[i])
            ans++;
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
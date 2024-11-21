#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] >= k)
            cnt += a[i];
        if (a[i] == 0 && cnt > 0)
            ans++, cnt--;
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
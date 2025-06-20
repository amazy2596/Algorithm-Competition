#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    deque<int> a(n), b(n), c;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1e9;
        for (int j = 0; j < n; j++)
            cnt = min(cnt, abs(a[j] - b[j]));
        b.push_back(b.front());
        b.pop_front();
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
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
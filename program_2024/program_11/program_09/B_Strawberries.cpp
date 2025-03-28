#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'O')
            cnt++;
        else
            cnt = 0;
        if (cnt == k)
            ans++, cnt = 0;
    }
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
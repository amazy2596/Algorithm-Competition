#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '<' && a[i] >= 0)
            a[i] = -1, ans++;
        if (s[i] == '>' && a[i] <= 0)
            a[i] = 1, ans++;

        if (s[i] == 'Z' && a[i - 1] * a[i] <= 0)
            a[i] = a[i - 1], ans++;
    }
    cout << ans << "\n";
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
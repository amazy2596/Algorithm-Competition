#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int len = s[0].length();
    for (int i = 0; i < n; i++)
        len = __gcd(len, (int)s[i].length());

    vector count(len, vector<int>(26));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s[i].length(); j++)
        {
            count[j % len][s[i][j] - 'a']++;
        }
    }

    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        int sum = 0, mx = 0;
        for (int j = 0; j < 26; j++)
        {
            sum += count[i][j];
            mx = max(mx, count[i][j]);
        }
        ans += sum - mx;
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // init();
    // cin >> T;
    while  (T--)
        solve();
    return 0;
}
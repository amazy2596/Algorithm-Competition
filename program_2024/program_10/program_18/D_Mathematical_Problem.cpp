#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if (n <= 2)
    {
        if (s[0] == '0')
            s.erase(s.begin());
        cout << s << "\n";
        return;
    }
    if (n == 3 && s[1] == '0')
    {
        cout << min((s[0] - '0') + (s[2] - '0'), (s[0] - '0') * (s[2] - '0')) << "\n";
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            cout << 0 << "\n";
            return;
        }
    }
    int ans = 1e9;
    for (int i = 0; i < s.length() - 1; i++)
    {
        int temp = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (i == j)
            {
                temp += 10 * (s[j] - '0') + (s[j + 1] - '0');
                j++;
                continue;
            }
            if (s[j] == '1')
                continue;
            temp += s[j] - '0';
        }
        ans = min(ans, temp);
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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s = "";
    for (int i = 1; i <= 2023; i++)
        s += to_string(i);

    int n = s.length();
    s = " " + s + " ";

    vector<int> pre_2(n + 2), suf_3(n + 2);
    for (int i = 1; i <= n; i++)
        pre_2[i] = pre_2[i - 1] + (s[i] == '2');

    for (int i = n; i >= 1; i--)
        suf_3[i] = suf_3[i + 1] + (s[i] == '3');

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (s[j] == '2')
                {
                    ans += pre_2[i] * suf_3[j];
                }
            }
        }
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
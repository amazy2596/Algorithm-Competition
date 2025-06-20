#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    for (int i = 1; i < s.length(); i++)
    {
        for (int j = i, count = 0; j > 0 && count < 9; j--, count++)
        {
            if (s[j] != '0' && (char)(s[j] - 1) > s[j - 1])
            {
                s[j] = (char)(s[j] - 1);
                swap(s[j - 1], s[j]);
            }
        }
    }
    cout << s << "\n";
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
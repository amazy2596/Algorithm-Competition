#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int sum = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '-')
            sum--;
        if (s[i] == '*')
            sum <<= 1;

        if (sum >= 2025)
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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
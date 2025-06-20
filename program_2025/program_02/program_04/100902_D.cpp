#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    if (s[0] == '1')
        cout << 2;
    else if (s[0] == '2')
        cout << 3;
    else if (s[0] == '3')
        cout << 5;
    else if (s[0] <= '6')
        cout << 7;
    else
        cout << 11;
    cout << string(s.length() - 1, '0') << "\n";
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
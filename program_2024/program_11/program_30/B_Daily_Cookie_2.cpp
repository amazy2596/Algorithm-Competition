#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (d > 0 && s[i] == '@')
            s[i] = '.', d--;
    }
    cout << s << "\n";
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
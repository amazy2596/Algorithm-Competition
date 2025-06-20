#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    cout << (s[0] - '0') + (s[1] - '0') << "\n";
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
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n; 
    string s;
    cin >> s;
    if (s[0] != s[n - 1])
        cout << "YES\n";
    else if (s[0] == s[n - 1])
        cout << "NO\n";
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
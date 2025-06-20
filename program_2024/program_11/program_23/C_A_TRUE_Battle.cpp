#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a = 0, b = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        a += s[i] == '1';
        b += s[i] == '0';
    }
    if (a >= b || s.find("11") != -1 || *s.begin() == '1' || *s.rbegin() == '1')
        cout << "YES\n";
    else 
        cout << "NO\n";
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
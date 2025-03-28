#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        a += s[i] == '1';
        b += s[i] == '2';
        c += s[i] == '3';
    }
    if (a == 1 && b == 2 && c == 3)
        cout << "Yes\n";
    else
        cout << "No\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
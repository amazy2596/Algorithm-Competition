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
        a += s[i] == 'Y';
        b += s[i] == 'N';
        c += s[i] == '-';
    }
    if (a >= 4)
        cout << 1;
    else 
    {
        if (b >= 2)
            cout << -1;
        else 
        {
            if (c > 0)
                cout << 0;
            else 
                cout << -1;
        }
    }
        
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
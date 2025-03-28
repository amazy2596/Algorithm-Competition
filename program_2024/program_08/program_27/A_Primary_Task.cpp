#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    if (s.length() <= 2)
        cout << "NO\n";
    else 
    {
        if (s[0] == '1' && s[1] == '0')
        {
            for (int i = 2; i < s.length(); i++)
            {
                if (s[i] == '0')
                {
                    cout << "NO\n";
                    return;
                }
                if (s[i] == '1' && i == s.length() - 1)
                {
                    cout << "NO\n";
                    return;
                }
                
                cout << "YES\n";
                return;
            }
        }
        else 
            cout << "NO\n";
    }
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
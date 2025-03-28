#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    int i = 0, j = 0;
    while (i < s.length() && j < t.length())
    {
        if (s[i] == '?')
        {
            s[i] = t[j];
            i++, j++;
            continue;
        }
        if (s[i] == t[j])
        {
            i++, j++;
            continue;
        }
        i++;
    }
    if (j == t.length())
    {
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '?')
                s[i] = 'a';
        cout << "YES\n";
        cout << s << "\n";
    }
    else 
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
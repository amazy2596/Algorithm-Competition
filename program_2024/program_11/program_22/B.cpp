#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    string x = a.substr(0, (a.find('.') == -1 ? a.length() : a.find('.')));
    string y = b.substr(0, (b.find('.') == -1 ? b.length() : b.find('.')));
    if (x != y)
        cout << "NO\n";
    else
    {
        x.clear();
        y.clear();
        if (a.find('.') == -1)
            x = "000000";
        else
        {
            int idx = a.find('.') + 1;
            while (x.length() < 6)
            {
                if (idx < a.length())
                    x += a[idx++];
                else
                    x += '0';
            }
        }
        if (b.find('.') == -1)
            y = "000000";
        else
        {
            int idx = b.find('.') + 1;
            while (y.length() < 6)
            {
                if (idx < b.length())
                    y += b[idx++];
                else
                    y += '0';
            }
        }
        if (x != y)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
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
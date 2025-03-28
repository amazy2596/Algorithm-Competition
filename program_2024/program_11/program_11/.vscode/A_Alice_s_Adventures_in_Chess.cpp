#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int x = 0, y = 0;
    if (a == y && b == x)
    {
        cout << "YES\n";
        return;
    }
    int num = 100;
    while (num--)
    {
        for (int i = 0; i < s.length(); i++)
        {
            x += s[i] == 'N';
            x -= s[i] == 'S';
            y += s[i] == 'E';
            y -= s[i] == 'W';
            if (a == y && b == x)
            {
                cout << "YES\n";
                return;
            }
        }
    }
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
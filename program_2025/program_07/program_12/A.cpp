#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, d, c;
        cin >> m >> d >> c;

        if (m > 7 || (m == 7 && d > 11))
            cout << "Too late!\n";
        else if ((m == 6 && d > 20) || m >= 7)
        {
            if (c < 2000)
                cout << "Need more!\n";
            else if (c == 2000)
                cout << "Ok!\n";
            else if (c > 2000)
                cout << "^_^\n";
        }
        else 
        {
            if (c < 1800)
                cout << "Need more!\n";
            else if (c == 1800)
                cout << "Ok!\n";
            else if (c > 1800)
                cout << "^_^\n";
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
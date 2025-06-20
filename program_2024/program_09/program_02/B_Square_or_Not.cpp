#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (sqrtf(n) - sqrt(n) != 0)
    {
        cout << "NO\n";
        return;
    }
    int pos = 0;
    bool f = 1;
    int r = sqrt(n);
    for (int i = 1; i <= r && f; i++)
    {
        for (int j = 1; j <= r && f; j++)
        {
            if (i == 1 || i == r || j == 1 || j == r)
            {
                if (s[pos] != '1')
                    f = 0;
            }
            else if (s[pos] != '0')
                f = 0;
            pos++;
        }
    }
    cout << (f ? "YES\n" : "NO\n");
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
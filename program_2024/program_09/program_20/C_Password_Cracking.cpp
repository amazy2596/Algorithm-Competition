#include <bits/stdc++.h>
#define int long long
using namespace std;

bool query(string s)
{
    cout << "? " << s << endl;
    int res;
    cin >> res;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    string ans = "";
    bool ok = true, f = false;
    while (ans.size() != n)
    {
        if (ok)
        {
            if (query(ans + '1'))
                ans = ans + '1';
            else if (query(ans + '0'))
                ans = ans + '0';
            else 
                ok = false, f = true;
        }
        if (!ok)
        {
            if (f)
            {
                ans = '0' + ans;
                f = false;
            }
            else if (query('1' + ans))
                ans = '1' + ans;
            else if (query('0' + ans))
                ans = '0' + ans;
        }
    }
    cout << "! " << ans << endl;
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
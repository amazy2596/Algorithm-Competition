#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    s = ' ' + s;
    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        int cnt = ceil(k * 1.0l / n);
        int remain = k - (cnt - 1) * n;
        int reverse = 0;
        while (cnt > 2)
        {
            int p = ceill(log2l(cnt)) - 1;
            int base = powl(2, p);
            int temp = cnt - base - 1;
            cnt = base - temp;
            reverse += p % 2 == 0;
        }
        reverse += cnt == 2;
        if (reverse % 2 == 1)
        {
            if (isupper(s[remain]))
                cout << (char)tolower(s[remain]) << " ";
            else
                cout << (char)toupper(s[remain]) << " ";
        }
        else
            cout << s[remain] << " ";
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
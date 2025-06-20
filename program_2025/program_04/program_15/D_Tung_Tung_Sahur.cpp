#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string p, s;
    cin >> p >> s;

    char ch = '#';
    int i = 0, j = 0, cnt = 0;
    while (i < p.length())
    {
        if (ch != '#' && p[i] != ch)
        {
            while (s[j] == ch && cnt)
                j++, cnt--;

            if (p[i] != s[j])
            {
                cout << "NO\n";
                return;
            }

            cnt = 0;
        }

        if (p[i] != s[j])
        {
            cout << "NO\n";
            return;
        }

        ch = p[i];
        i++, j++, cnt++;
    }

    while (s[j] == ch && cnt)
        j++, cnt--;

    if (j < s.length())
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (char ch = 'a'; ch <= 'z' && m > 0; ch++)
    {
        int ed = n - 1;
        while (ed >= 0 && s[ed] != ch)
            ed--;
        while (ed >= 0 && s[ed] == ch)
            ed--;

        for (int i = 0; i <= ed; i++)
        {
            if (ch == s[i] && m - a[i] >= 0)
                b[i] = 1, m -= a[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (b[i])
            cout << string(2, s[i]);
        else 
            cout << s[i];
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
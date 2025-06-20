#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == 's')
        s.erase(s.begin());
    if (s.back() == 'p')
        s.pop_back();
    bool a = 0, b = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 's')
            a = 1;
        if (s[i] == 'p')
            b = 1;
        if (a && b)
        {
            cout << "NO\n";
            return;
        }
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
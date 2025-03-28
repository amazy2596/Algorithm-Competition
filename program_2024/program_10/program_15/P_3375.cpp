#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    string ss = t + "#" + s;
    vector<int> pi(ss.length());
    for (int i = 1, len = pi[i - 1]; i < ss.length(); i++)
    {
        while (len && ss[i] != ss[len])
            len = pi[len - 1];
        if (ss[i] == ss[len])
            pi[i] = ++len;
        if (len == t.length())
        {
            cout << i - 2 * t.length() + 1 << "\n";
            len = pi[len - 1];
        }
    }
    for (int i = 0; i < t.length(); i++)
        cout << pi[i] << " ";
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
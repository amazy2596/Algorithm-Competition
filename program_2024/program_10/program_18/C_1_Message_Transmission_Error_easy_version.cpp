#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string t;
    cin >> t;
    for (int k = 1; k < t.length(); k++)
    {
        int i = k, j = 0;
        // cout << t << "\n" << t.substr(i, t.length() - i + 1) << "\n";
        while (i < t.length() && t[i] == t[j])
            i++, j++;
        if (i == t.length() && t.substr(0, k) != t.substr(k) && 2 * t.substr(k).length() > t.length())
        {
            cout << "YES\n";
            cout << t.substr(k) << "\n";
            return;
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
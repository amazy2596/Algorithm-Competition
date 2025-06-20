#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    string ans = s.substr(0, 1);
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != ans.back())
            ans += s[i];
    }

    if (ans.size() <= 5)
        cout << "Yes\n";
    else 
        cout << "No\n";
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
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
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
        ans += s[i] == 'y';

    int i = 1;
    while (i < s.length())
    {
        if (s[i - 1] == 'n' && s[i] == 'n')
            ans++, i += 2;
        else    
            i++;
    }

    cout << ans << "\n";
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
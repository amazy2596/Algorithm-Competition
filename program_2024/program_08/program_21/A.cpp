#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    map<char, int> mp;
    mp[s[0]]++, mp[s[1]]++, mp[s[2]]++;
    if (mp.size() == 3)
        cout << 2 << "\n";
    else if (mp.size() == 2)
        cout << 1 << "\n";
    else 
        cout << 0 << "\n";
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
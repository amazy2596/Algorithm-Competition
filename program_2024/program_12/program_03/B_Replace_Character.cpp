#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[s[i]]++;
    char ch1, ch2;
    int mx = 0, mn = 1e9;
    for (auto [key, val] : mp)
    {
        if (val > mx)
        {
            ch1 = key;
            mx = val;
        }
        if (val <= mn)
        {
            ch2 = key;
            mn = val;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ch2)
        {
            s[i] = ch1;
            break;
        }
    }
    cout << s << "\n";
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
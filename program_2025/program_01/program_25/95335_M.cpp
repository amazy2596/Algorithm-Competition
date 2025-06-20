#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    map<char, int> mp;
    string tar = "nowcoder";
    for (auto ch : tar)
        mp[ch] = 0;
    for (auto ch : s)
    {
        if (mp.find(ch) != mp.end())
            mp[ch]++;
    }

    for (auto [key, val] : mp)
    {
        if (val == 0 || (key == 'o' && val == 1))
        {
            cout << "I AK IOI";
            return;
        }
    }

    cout << "happy new year";
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
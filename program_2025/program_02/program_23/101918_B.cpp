#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    map<char, int> mp;
    for (auto ch : a)
        mp[ch]++;

    for (int i = 0; i < b.length(); i++)
    {
        if (a[i] == b[i])
            cout << "g";
        else if (mp.find(b[i]) != mp.end())
            cout << "y";
        else 
            cout << "r";
    }

    cout << (a == b ? "\ncongratulations" : "\ndefeat");
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
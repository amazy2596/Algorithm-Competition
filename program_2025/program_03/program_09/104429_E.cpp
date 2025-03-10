#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<string, string> mp;
    string temp;
    getline(cin, temp);
    for (int i = 0; i < n; i++)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        mp[a] = b;
    }

    string q;
    getline(cin, q);
    if (mp.find(q) != mp.end())
        cout << mp[q] << "\n";
    else 
        cout << "The server is busy, please try again later." << "\n";
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
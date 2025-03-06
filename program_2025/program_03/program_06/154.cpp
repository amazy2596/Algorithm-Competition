#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    map<string, vector<string>> mp;
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        s = " " + s;
        string key = "";
        for (int j = 0; j < s.length() - 1; j++)
            if (s[j] == ' ' && s[j + 1] != ' ')
                key.push_back(s[j + 1]);
        mp[key].push_back(s.substr(1));
    }
    for (auto &[key, val] : mp)
    {
        sort(mp[key].begin(), mp[key].end());
        // sort(mp[key].begin(), mp[key].end(), [&](string &a, string &b)
        // {
            // if (a.length() == b.length())
            // {
                // for (int i = 0; i < a.length(); i++)
                // {
                    // if (a[i] < b[i])
                        // true;
                    // else if (a[i] > b[i])
                        // return false;
                // }
            // }
            // return a.length() < b.length();
        // });
    }

    int m;
    cin >> m;
    getline(cin, s);
    for (int i = 0; i < m; i++)
    {
        getline(cin, s);
        s = " " + s;
        string key = "";
        for (int j = 0; j < s.length() - 1; j++)
            if (s[j] == ' ' && s[j + 1] != ' ')
                key.push_back(s[j + 1]);
        
        vector<string> &v = mp[key];
        if (v.size() == 0)
            cout << s.substr(1) << "\n";
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << "|\n"[i == v.size() - 1];
    }
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
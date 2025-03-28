#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    while (m--)
    {
        string s;
        cin >> s;
        if (s.length() != a.size())
        {
            cout << "NO\n";
            continue;
        }
        unordered_map<char, int> mp1;
        unordered_map<int, char> mp2;
        bool f = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp1.find(s[i]) == mp1.end())
                mp1[s[i]] = a[i];
            else if (mp1[s[i]] != a[i])
            {
                f = 0;
                break;
            }
            if (mp2.find(a[i]) == mp2.end())
                mp2[a[i]] = s[i];
            else if (mp2[a[i]] != s[i])
            {
                f = 0;
                break;
            }
        }
        cout << (f ? "YES\n" : "NO\n");
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
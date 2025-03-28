#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    s = ' ' + s;
    map<int, int> mp;
    set<int> ss;
    for (int i = 4; i < s.length(); i++)
    {
        string temp = s.substr(i - 3, 4);
        if (temp == "1100")
            ss.insert(i - 3);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int i, vv;
        cin >> i >> vv;
        char v = '0' + vv;
        if (s.length() <= 4)
        {
            cout << "NO\n";
            continue;
        }
        if (s[i] == v)
        {
            cout << (ss.size() == 0 ? "NO\n" : "YES\n");
            continue;
        }
        s[i] = v;
        for (int idx = max(1ll, i - 3); idx <= i; idx++)
        {
            if (ss.count(idx))
                ss.erase(idx);
        }
        for (int idx = max(1ll, i - 3); idx <= i; idx++)
        {
            if (idx + 3 < s.length())
            {
                string cur = s.substr(idx, 4);
                if (cur == "1100")
                    ss.insert(idx);
            }
        }
        cout << (ss.size() == 0 ? "NO\n" : "YES\n");
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
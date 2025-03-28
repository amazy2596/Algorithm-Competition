#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    deque<char> mn, cur;
    for (int i = 0; i < s.length(); i++)
    {
       mn.push_back(s[i]);
       cur.push_back(s[i]);
    }
    auto compare = [&](deque<char> cur)
    {
        for (int i = 0; i < cur.size(); i++)
        {
            if (cur[i] < mn[i])
                return true;
            else if (cur[i] > mn[i])
                return false;
        }
        return false;
    };
    int count = 11;
    while (count--)
    {
        cur.push_back(cur.front());
        cur.pop_front();
        if (compare(cur))
            mn = cur;
    }
    for (int i = 0; i < mn.size(); i++)
        cout << mn[i];
    cout << "\n";
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
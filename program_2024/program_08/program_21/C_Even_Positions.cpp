#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int balance = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '_')
        {
            if (balance <= 0)
                s[i] = '(';
            else
                s[i] = ')';
        }
        balance += s[i] == '(';
        balance -= s[i] == ')';
    }
    int ans = 0;
    queue<string> q;
    q.push(s);
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int l = 0, bal = 0;
        for (int r = 0; r < cur.length(); r++)
        {
            bal += cur[r] == '(';
            bal -= cur[r] == ')';
            if (bal == 0)
            {
                ans += r - l;
                q.push(cur.substr(l + 1, r - l - 1));
                l = r + 1;
            }
        }
    }
    cout << ans << "\n";
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
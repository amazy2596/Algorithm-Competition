#include <bits/stdc++.h>
#define int long long
using namespace std;

int calc(string s)
{
    int res = 2;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i - 1] == s[i])
            res += 1;
        else 
            res += 2;
    }
    return res;
}

void solve()
{
    string s;
    cin >> s;
    if (s.length() == 1)
    {
        s = s + (s[0] == 'a' ? 'b' : 'a');
        cout << s << "\n";
        return;
    }
    string ans;
    int num = calc(s);
    for (int i = 1; i < s.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            string cur = s.substr(0, i) + char('a' + j) + s.substr(i, s.length() - i);
            int temp = calc(cur);
            if (temp > num)
                ans = cur, num = temp;
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
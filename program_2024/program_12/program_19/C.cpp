#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    int cnt = 0;
    string s = "";
    if (a > b)
        s += '0', a--;
    else
        s += '1', b--;
    while (cnt < k - 1 && a > 0 && b > 0)
    {
        if (s.back() == '1')
            s += '0', a--;
        else if (s.back() == '0')
            s += '1', b--;
        cnt++;
    }
    if (s.back() == '0')
    {
        while (a--)
            s += '0';
        while (b--)
            s += '1';
    }
    else if (s.back() == '1')
    {
        while (b--)
            s += '1';
        while (a--)
            s += '0';
    }
    int count = 0;
    for (int i = 1; i < s.length(); i++)
        count += s[i - 1] != s[i];
    if (count == k)
        cout << s << "\n";
    else
        cout << -1 << "\n";
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
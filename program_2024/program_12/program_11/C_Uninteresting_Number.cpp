#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int sum = 0, a = 0, b = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += s[i] - '0';
        a += s[i] == '2';
        b += s[i] == '3';
    }
    if (sum % 9 == 0)
    {
        cout << "YES\n";
        return;
    }
    int diff1 = (sum / 9 + 1) * 9 - sum, diff2 = (sum / 9 + 2) * 9 - sum;
    bool f = 0;
    
    diff1 -= min(b, diff1 / 6) * 6;
    diff1 -= min(a, diff1 / 2) * 2;
    if (diff1 == 0)
        f = 1;
    
    diff2 -= min(b, diff2 / 6) * 6;
    diff2 -= min(a, diff2 / 2) * 2;
    if (diff2 == 0)
        f = 1;
    
    cout << (f ? "YES\n" : "NO\n");
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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        int x = (a[0] - '0') * 10 + (a[1] - '0');
        int y = 0;
        for (int i = 1; i < b.length(); i++)
            y = (y * 10 + (b[i] - '0'));
        if (b[0] == '-')
            y = -y;
        x = (x + y + 24) % 24;
        string ans = to_string(x);
        cout << (ans.length() == 2 ? ans : "0" + ans) << a.substr(2) << "\n";
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
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    int ans = (1 + n) * n / 2;
    queue<int> q;
    for (int i = n; i >= 1; i--)
    {
        if ((s[i] == '0' && !q.empty()) || i <= q.size())
        {
            ans -= q.front();
            q.pop();
        }
        if (s[i] == '1')
            q.push(i);
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
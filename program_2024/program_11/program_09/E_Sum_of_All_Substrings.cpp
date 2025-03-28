#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    deque<int> ans;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += (s[i] - '0') * (i + 1);
        ans.push_back(cur);
    }
    int t = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] += t;
        t = ans[i] / 10;
        ans[i] %= 10;
    }
    if (t)
        ans.push_front(t);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
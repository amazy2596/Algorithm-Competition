#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans;
    for (int i = 0; i < s.length(); i++)
        ans.push_back(s[i] - '0');
    int pre = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] += pre;
        pre += s[i] - '0';
    }
    reverse(ans.begin(), ans.end());
    int t = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] += t;
        t = ans[i] / 10;
        ans[i] %= 10;
    }
    while (t)
    {
        ans.push_back(t);
        t = ans.back() / 10;
        ans.back() %= 10;
    }
    while (!ans.back())
        ans.pop_back();
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
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
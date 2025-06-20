#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    string s;
    cin >> s;
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++)
        l += s[i] == 'L', r -= s[i] == 'R';
    vector<int> ans;
    int cur = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        l -= s[i] == 'L', r += s[i] == 'R';
        if (s[i] == 'L')
            cur = (cur * a[l]) % m;
        else
            cur = (cur * a[r]) % m;
        ans.push_back(cur);
    }
    for (int i = n - 1; i >= 0; i--)
        cout << ans[i] << " \n"[i == 0];
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
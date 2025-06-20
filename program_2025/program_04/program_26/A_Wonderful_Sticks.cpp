#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> a(n + 1);
    int mx = n, mn = 1;
    for (int i = s.length() - 1; i >= 1; i--)
    {
        if (s[i] == '>')
            a[i + 1] = mx--;
    }
    for (int i = s.length() - 1; i >= 1; i--)
    {
        if (s[i] == '<')
            a[i + 1] = mn++;
    }
    a[1] = mx;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
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
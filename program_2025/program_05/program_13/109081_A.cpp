#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<char> ch(n);
    for (int i = 0; i < n; i++)
        cin >> ch[i];
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        s = s.substr(0, s.find('/'));
        for (int j = 0; j < s.length(); j++)
            a[i] = (a[i] * 10 + s[j] - '0');
    }

    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[idx])
            idx = i;
    }

    cout << ch[idx];
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
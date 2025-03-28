#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt(26);
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
    int mx = 0;
    for (int i = 0; i < 26; i++)
        mx = max(mx, cnt[i]);
    string b = s;
    sort(b.begin(), b.end());
    vector<int> cur(26);
    for (int i = 1; i < 26; i++)
        cur[i] = cur[i - 1] + cnt[i - 1];
    vector<int> id(n);
    for (int i = 0; i < n; i++)
        id[i] = cur[s[i] - 'a']++;
    string t;
    for (int i = 0; i < n; i++)
        t.push_back(b[(id[i] + mx) % n]);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[i])
        {
            cout << -1 << "\n";
            return;
        }
    }
    cout << t << "\n";
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
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
    int len = 1;
    map<int, int> mp;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i - 1] == s[i])
            len++;
        else
        {
            if (len > 1)
                mp[len]++;
            len = 1;
        }
    }
    if (len > 1)
        mp[len]++;

    vector<int> l(n + 2, n);
    int sum = 0;
    for (int i = n; i >= 1; i--)
    {
        l[i] = l[i + 1];
        l[i] -= sum;
        if (mp.find(i) != mp.end())
            sum += mp[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans ^= (i * l[i]);
    cout << ans << "\n";
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
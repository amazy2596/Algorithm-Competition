#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            pi[i] = ++j;
    }
    if (pi[n - 1] > n / 2)
    {
        cout << "YES\n";
        cout << s.substr(0, pi[n - 1]) << "\n";
    }
    else 
        cout << "NO\n";
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
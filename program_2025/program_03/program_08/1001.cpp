#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string tar;
    cin >> tar;
    
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    
    for (int i = 1; i <= n; i++)
    {
        if (tar == s[i])
        {
            cout << i << "\n";
            return;
        }
    }

    cout << "-1\n";
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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == m || n - m > 26)
    {
        cout << "NO\n";
        return;
    }

    string s;
    for (int i = 0; i < n; i++)
        s += 'a' + i % (n - m);
        
    cout << "YES\n";
    cout << s << "\n";
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
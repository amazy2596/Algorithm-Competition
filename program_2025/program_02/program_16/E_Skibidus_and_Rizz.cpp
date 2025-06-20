#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (max(n, m) < k || max(n, m) - min(n, m) > k)
    {
        cout << "-1\n";
        return;
    }

    string s = "";
    while (max(n, m) > k)
    {
        if (n > m)
            s += "01";
        else 
            s += "10";
        n--, m--;
    }

    if (s.back() == '1')
    {
        while (n--)
            s += '0';
        while (m--)
            s += '1';
    }
    else 
    {
        while (m--)
            s += '1';
        while (n--)
            s += '0';
    }

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
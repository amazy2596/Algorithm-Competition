#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i % 2 == 0)
            even += x;
        else
            odd += x;
    }
    if (n % 2 == 0)
    {
        if (even % (n / 2) == 0 && odd % (n / 2) == 0 && even / (n / 2) == odd / (n / 2))
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    else
    {
        if (even % (n / 2 + 1) == 0 && odd % (n / 2) == 0 && even / (n / 2 + 1) == odd / (n / 2))
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
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
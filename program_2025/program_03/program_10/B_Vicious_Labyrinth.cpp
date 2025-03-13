#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k % 2 == 0)
    {
        for (int i = 0; i < n - 2; i++)
            cout << n - 1 << " ";
        cout << n << " " << n - 1 << "\n";
    }
    else 
    {
        for (int i = 0; i < n - 2; i++)
            cout << n << " ";
        cout << n << " " << n - 1 << "\n";
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
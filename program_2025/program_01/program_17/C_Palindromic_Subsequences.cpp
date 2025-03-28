#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n == 6)
        cout << "1 1 2 3 1 2\n";
    else 
    {
        cout << "1 ";
        for (int i = 0, num = 2; i < n - 3; i++)
            cout << num++ << " ";
        cout << "1 1\n";
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
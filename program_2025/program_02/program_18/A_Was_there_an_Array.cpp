#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n - 2);
    for (int i = 0; i < n - 2; i++)
        cin >> b[i];
    
    for (int i = 0; i < n - 4; i++)
    {
        if (b[i] == 1 && b[i + 1] == 0 && b[i + 2] == 1)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
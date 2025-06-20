#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    map<int, int> mp = {{1, 1}, {2, 1}, {3, 1}, {5, 1}, {6, 1}};
    for (int i = 0; i < 7; i++)
    {
        int x;
        cin >> x;
        if (mp.find(x) == mp.end())
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
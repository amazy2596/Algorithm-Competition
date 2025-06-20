#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    if (a1 == b1)
        cout << (a2 < b2 ? "A" : "B");
    else 
        cout << (a1 < b1 ? "A" : "B");
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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
        cout << "biii\nstop\n";
    else if (a == 0 && b == 1)
        cout << "-\nstop\n";
    else if (a == 1 && b == 0)
        cout << "dudu\nmove\n";
    else if (a == 1 && b == 1)
        cout << "-\nmove\n";
    else if (a == 2 && b == 0)
        cout << "-\nstop\n";
    else if (a == 2 && b == 1)
        cout << "-\nstop\n";
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
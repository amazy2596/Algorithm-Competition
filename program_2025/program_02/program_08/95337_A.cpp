#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int x;
    char ch;
    cin >> x >> ch;
    if (ch == '*')
        cout << x << " " << 1 << "\n";
    else if (ch == '+')
        cout << x - 1 << " " << 1 << "\n";
    else if (ch == '-')
        cout << x + 1 << " " << 1 << "\n";
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
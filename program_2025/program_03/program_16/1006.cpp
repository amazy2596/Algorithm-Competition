#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + 2 * b + 4 * c) % 4 == 0)
        cout << "Bob\n";
    else 
        cout << "Alice\n";
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
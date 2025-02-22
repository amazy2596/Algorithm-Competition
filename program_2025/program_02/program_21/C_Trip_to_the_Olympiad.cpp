#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    int k = 31 - __builtin_clz(l ^ r);
    int a = l | ((1 << k) - 1), b = a + 1, c = a == l ? r : l;
    cout << a << " " << b << " " << c << "\n";
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
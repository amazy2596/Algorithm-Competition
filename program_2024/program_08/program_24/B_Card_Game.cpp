#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(int a, int b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    return 0;
}

void solve()
{
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int ans = 0;
    ans += f(a1, b1) + f(a2, b2) > 0;
    ans += f(a1, b2) + f(a2, b1) > 0;
    ans += f(a2, b1) + f(a1, b2) > 0;
    ans += f(a2, b2) + f(a1, b1) > 0;
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
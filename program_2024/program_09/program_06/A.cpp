#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    auto check = [&](int a, int b, int c)
    {
        bool f = 1;
        if (a + b <= c)
            f = 0;
        if (a + c <= b)
            f = 0;
        if (b + c <= a)
            f = 0;
        if (a - b >= c)
            f = 0;
        if (b - a >= c)
            f = 0;
        if (a - c >= b)
            f = 0;
        if (c - a >= b)
            f = 0;
        if (b - c >= a)
            f = 0;
        if (c - b >= a)
            f = 0;
        return f;
    };
    bool f = 0;
    if (check(2 * a, b, c))
        f = 1;
    if (check(a, 2 * b, c))
        f = 1;
    if (check(a, b, 2 * c))
        f = 1;
    cout << (f ? "Yes\n" : "No\n");
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
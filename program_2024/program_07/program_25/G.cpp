#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    intt xg, yg, xt, yt;
    cin >> xg >> yg >> xt >> yt;
    xg = -xg;
    long double ans1 = sqrtl(abs(xg - xt) * abs(xg - xt) + abs(yg - yt) * abs(yg - yt));
    xg = -xg;
    yg = -yg;
    long double ans2 = sqrtl(abs(xg - xt) * abs(xg - xt) + abs(yg - yt) * abs(yg - yt));
    cout << fixed << setprecision(10) << min(ans1, ans2) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
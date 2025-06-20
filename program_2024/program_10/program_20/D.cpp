#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> d >> c;
    int sum = 0, cnt;
    cnt = min(a, b);
    sum += cnt;
    a -= cnt, b -= cnt;
    cnt = min(b, c);
    sum += cnt;
    b -= cnt, c -= cnt;
    cnt = min(c, d);
    sum += cnt;
    c -= cnt, d -= cnt;
    cnt = min(d, a);
    sum += cnt;
    d -= cnt, a -= cnt;
    cout << (sum % 2 == 0 ? "yukari\n" : "kou\n");
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
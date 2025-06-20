#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int c = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int a = n % 10;
    cout << b << c << a << " " << c << a << b << "\n";
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
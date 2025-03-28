#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b - a > d - c)
    {
        cout << b << " " << d << endl;
        cout << b - 1 << " " << d << endl;
        cout << a << " " << d - 1 << endl;
    } 
    else 
    {
        cout << b << " " << d << endl;
        cout << b << " " << d - 1<< endl;
        cout << b - 1 << " " << c << endl; 
    }
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
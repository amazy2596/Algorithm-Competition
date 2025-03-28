#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int s;
    cin >> s;
    if (sqrtf(s) - sqrt(s) == 0)
        cout << 0 << "\n";
    else 
        cout << 3 << "\n";
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
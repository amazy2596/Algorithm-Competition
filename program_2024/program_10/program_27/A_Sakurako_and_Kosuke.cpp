#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    int x = 0;
    for (int i = 1; i <= 100; i++)
    {
        int move = 2 * i - 1;
        if (i % 2 == 1)
            move = -move;
        x += move;
        if (x <= n && x >= -n)
            ans++;
        else 
            break;
    }
    cout << (ans % 2 == 0 ? "Sakurako\n" : "Kosuke\n");
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
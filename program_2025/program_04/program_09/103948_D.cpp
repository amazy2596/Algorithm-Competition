#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    bool ok[2][2];
    ok[0][1] = ok[1][0] = ok[1][1] = false;
    ok[0][0] = true;
    int x = 0, y = 0, cnt = 0;
    for(int i = n - 1; i >= 1; i--)
    {
        if(s[i] == '0')
            x ^= 1;
        else 
            y ^= 1;
        if(ok[x][y]) 
            cnt++;
        ok[x][y] = true;
    }
    
    cout << fixed << setprecision(6) << cnt * 1.0 / n << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
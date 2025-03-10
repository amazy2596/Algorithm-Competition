#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<string> g(pow(3, n));
    for (int i = 0; i < pow(3, n); i++)
        g[i] = string(pow(3, n), '#');

    auto calc = [&](auto calc, int k, int i, int j) -> void
    {
        if (k == 0)
            return;
        
        int mn_i = i - (pow(3, k - 1) / 2) + 1, mn_j = j - (pow(3, k - 1) / 2) + 1;
        int mx_i = i + (pow(3, k - 1) / 2), mx_j = j + (pow(3, k - 1) / 2);
        for (int x = mn_i; x <= mx_i; x++)
            for (int y = mn_j; y <= mx_j; y++)
                g[x][y] = '.';
            
        for (int t = 0; t < 8; t++)
        {
            int cnt = pow(3, k - 1);
            int nx = i, ny = j;
            if (t == 0)
                nx -= cnt, ny -= cnt;
            else if (t == 1)
                nx -= cnt;
            else if (t == 2)
                nx -= cnt, ny += cnt;
            else if (t == 3)
                ny += cnt;
            else if (t == 4)
                nx += cnt, ny += cnt;
            else if (t == 5)
                nx += cnt;
            else if (t == 6)
                nx += cnt, ny -= cnt;
            else if (t == 7)
                ny -= cnt;

            calc(calc, k - 1, nx, ny);
        }  
    };

    calc(calc, n, pow(3, n) / 2, pow(3, n) / 2);

    for (int i = 0; i < pow(3, n); i++)
    {
        for (int j = 0; j < pow(3, n); j++)
        {
            cout << g[i][j];
        }
        cout << "\n";
    }
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
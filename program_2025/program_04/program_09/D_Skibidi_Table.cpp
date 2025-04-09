#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        string op;
        cin >> op;
        if (op == "->")
        {
            int x, y;
            cin >> x >> y;

            auto dfs = [&](auto dfs, int base, int n, int base_x, int base_y) -> int
            {
                if (n == 0)
                    return base;
                int dx = 1ll << (n - 1), dy = 1 << (n - 1);
                int sum = 1ll << (2 * n - 2);
                if (x < base_x + dx && y < base_y + dy)
                    return dfs(dfs, base, n - 1, base_x, base_y);
                else if (x >= base_x + dx && y >= base_y + dy)
                    return dfs(dfs, base + sum, n - 1, base_x + dx, base_y + dy);
                else if (x >= base_x + dx && y < base_y + dy)
                    return dfs(dfs, base + 2 * sum, n - 1, base_x + dx, base_y);
                else 
                    return dfs(dfs, base + 3 * sum, n - 1, base_x, base_y + dy);
            };

            cout << dfs(dfs, 1, n, 1, 1) << "\n";
        }
        else 
        {
            int d;
            cin >> d;

            auto dfs = [&](auto dfs, int base, int n, int x, int y) -> pair<int, int>
            {
                if (n == 0)
                    return {x, y};

                int dx = 1ll << (n - 1), dy = 1 << (n - 1);
                int sum = 1ll << (2 * n - 2);

                if (d < base + sum)
                    return dfs(dfs, base, n - 1, x, y);
                else if (d < base + 2 * sum)
                    return dfs(dfs, base + sum, n - 1, x + dx, y + dy);
                else if (d < base + 3 * sum)
                    return dfs(dfs, base + sum * 2, n - 1, x + dx, y);
                else 
                    return dfs(dfs, base + sum * 3, n - 1, x, y + dy);
            };

            auto [x, y] = dfs(dfs, 1, n, 1, 1);
            cout << x << " " << y << "\n";
        }
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
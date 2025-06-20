#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

unsigned seed;
unsigned rnd()
{
	unsigned ret=seed;
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return ret;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k >> seed;
    vector<vector<int>> st(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            st[i][j] = j;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    for (int t = 1; t <= k; t++)
    {
        int op = (rnd() % 2) + 1;
        if (op == 1)
        {
            int i = (rnd() % m) + 1;
            int x = (rnd() % (n * m)) + 1;
            if (st[i].empty())
                continue;
            for (auto row : st[i])
                g[row][i] = x;
            st[i].clear();
        }
        else if (op == 2)
        {
            int a = (rnd() % n) + 1;
            int b = (rnd() % m) + 1;
            st[b].push_back(a);
            g[a][b] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans ^= g[i][j] * ((i - 1) * m + j);
        }
    }
    cout << ans << "\n";
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
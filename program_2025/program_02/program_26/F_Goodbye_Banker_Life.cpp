#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    
    auto dfs = [&](auto dfs, int n) -> string
    {
        if ((n & (n - 1)) == 0)
        {
            string res = "";
            for (int i = 0; i < n; i++)
                res += to_string(k) + " ";
            return res;
        }

        int cnt = 31 - __builtin_clz(n);
        int remain = n - (1ll << cnt);

        string segment = dfs(dfs, remain);
        string ans = segment;
        for (int i = 0; i < (1ll << cnt) - remain && (n & (n - 1)) != 0; i++)
            ans += "0 ";
        ans += segment;
        return ans;
    };

    cout << dfs(dfs, n) << "\n";

    // vector a(n + 1, vector<int>(1));
    // a[1].push_back(k);
    // cout << string(15, ' ') << a[1][1] << "\n";
    // for (int i = 2; i <= n; i++)
    // {
    //     a[i].resize(i + 1, 0);
    //     cout << string(16 - i, ' ');
    //     for (int j = 1; j <= i; j++)
    //     {
    //         if (1 < j && j < i)
    //             a[i][j] = a[i - 1][j - 1] ^ a[i - 1][j];
    //         else if (j == 1)
    //             a[i][j] = a[i - 1][j];
    //         else if (j == i)
    //             a[i][j] = a[i - 1][j - 1];
    //         cout << a[i][j] << " ";
    //     }

    //     cout << "\n";
    // }
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